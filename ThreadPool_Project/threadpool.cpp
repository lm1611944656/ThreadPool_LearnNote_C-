#include "threadpool.h"


/*********************CThreadPool***********************/
/*线程的构造函数*/
CThreadObj::CThreadObj(ThreadFunc threadFunc)
:threadFunc_(threadFunc),
 thread_(nullptr){

}

/*线程的析构函数*/
CThreadObj::~CThreadObj(){
    if (thread_ && thread_->joinable()) {
        thread_->join(); // 确保线程结束再销毁
    }
}

void CThreadObj::start(){
    thread_ = std::make_unique<std::thread>(threadFunc_);
//    std::thread t(threadFunc_);
//    t.detach();
}

std::thread& CThreadObj::getThread() {
    return *thread_;
}

/**********************END***************************/
const int TASK_MAX_THRESHOLD = 4;

CThreadPool::CThreadPool()
:initThreadSize_(0),
 taskSize_(0),
 taskQueMaxThreshold_(TASK_MAX_THRESHOLD),
 poolMode_(TThreadPoolModel::MODE_FIXED)
{
    deInit();
}

CThreadPool::~CThreadPool() = default;

void CThreadPool::deInit() {
    threads_.clear();
}

void CThreadPool::start(unsigned int initThreadSize) {
    /*保存线程数量*/
    initThreadSize_ = initThreadSize;

    /*集中创建线程*/
    for(int i = 0; i < initThreadSize_; i++){
        /*创建线程对象之后，需要将线程所要执行的线程函数给线程*/
        std::unique_ptr<CThreadObj> pThreadObj = std::make_unique<CThreadObj>(std::bind(&CThreadPool::threadFunc, this));
        threads_.emplace_back(std::move(pThreadObj));
    }

    /*集中启动线程对象*/
    for(int i = 0; i < initThreadSize_; i++){
        threads_[i]->start();
    }

//    // 主线程等待所有子线程完成
//    for (auto& threadObj : threads_) {
//        if (threadObj->getThread().joinable()) {
//            threadObj->getThread().join();
//        }
//    }
}

void CThreadPool::threadFunc(){
    std::shared_ptr<CThreadTask> task;
    while (true){
        {
            /*获取锁*/
            std::unique_lock<std::mutex> lock(taskQueMtx_);

            /*判断队列是否为空*/
            notEmpty_.wait(lock, [&]()->bool{return !taskQueue_.empty();});

            /*从任务队列中获取一个任务*/
            task = taskQueue_.front();
            taskQueue_.pop();
            taskSize_--;

            /*再次判断任务队列中是否有任务，如果有进行通知,赶紧来消费*/
            if(!taskQueue_.empty()){
                notEmpty_.notify_all();
            }

            /*取出一个任务了，需要通知生产者生产任务*/
            notFull_.notify_all();
        }
        if(task != nullptr){
            /*执行任务*/
            task->run();
        }
    }
}

void CThreadPool::setMode(TThreadPoolModel poolModel) {
    poolMode_ = poolModel;
}

void CThreadPool::setTaskQueMaxThreshold(unsigned int threshold){
    taskQueMaxThreshold_ = threshold;
}

void CThreadPool::submitTask(std::shared_ptr<CThreadTask> sp) {
    /*获取锁；可以将【std::unique_lock】看做一个容器，并且这个容器只能放置一把锁*/
    std::unique_lock<std::mutex> lock(taskQueMtx_);

    /*判断队列是否为空, 方式一*/
//    while (taskQueue_.size() == TASK_MAX_THRESHOLD){
//        noEmpty_.wait(lock);
//    }
    /*判断队列是否为空，方式2; 只有当【taskQueue_.size() < TASK_MAX_THRESHOLD】满足，wait才不会阻塞*/
    bool result = notEmpty_.wait_for(lock, std::chrono::seconds(1), [&]()->bool {return taskQueue_.size() < TASK_MAX_THRESHOLD;});
    if(!result){
        // 表示notEmpty_等待了1s钟，条件依然没有满足；
        std::cerr << "task queue full, submit task fail." << std::endl;
        return;
    }
    /*往任务队列中存放任务*/
    taskQueue_.emplace(sp);
    taskSize_++;

    /*通知线程，任务队列中有任务，需要开始执行了*/
    notFull_.notify_all();
}




