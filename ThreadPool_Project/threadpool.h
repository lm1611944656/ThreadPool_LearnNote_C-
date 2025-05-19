#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <vector>
#include <queue>                // 困
#include <memory>
#include <atomic>
#include <mutex>                // 保证线程同步机制
#include <condition_variable>   // 线程之间的通讯机制
#include <functional>           // 函数指针
#include <thread>
#include <chrono>               // 靠楼，内部封装了很多时间单位


/*线程池支持的模型 */
typedef enum{
    MODE_FIXED,     // 线程池是固定模式(线程池中线程数量固定)
    MODEL_CACHED    // 线程池是不固定模式(线程池中线程数量不固定)
} TThreadPoolModel;

/*线程池中的线程对象*/
class CThreadObj
{
public:
    using ThreadFunc = std::function<void ()>;

    /*线程的构造函数*/
    explicit CThreadObj(ThreadFunc threadFunc);

    /*线程的析构函数*/
    ~CThreadObj();
public:
    /*启动线程*/
    void start();

    /* 获取线程对象用于 join*/
    std::thread& getThread();
private:
    ThreadFunc threadFunc_;
    std::unique_ptr<std::thread> thread_;
};

/*线程池中线程需要执行的任务*/
class CThreadTask{
public:
    /*用户只需要继承CThreadTask类，并且重写run()方法；
     * 用户既可以自定义任意类型任务
     * */
    virtual void run() = 0;
};

class CThreadPool {
public:
    explicit CThreadPool();
    ~CThreadPool();

    CThreadPool(const CThreadPool &) = delete;
    CThreadPool& operator= (const CThreadPool &) = delete;
public:
    /*开启线程池*/
    void start(unsigned int initThreadSize = 4);

    /*设置线程池的模式*/
    void setMode(TThreadPoolModel poolModel);

    /*设置任务队列上限阈值*/
    void setTaskQueMaxThreshold(unsigned int threshold);

    /*给任务队列提交任务*/
    void submitTask(std::shared_ptr<CThreadTask> sp);

private:
    /*线程池的初始化方法*/
    void deInit();

    /*线程池中的线程需要执行的任务(线程池中有线程，那线程所要执行的线程函数也需要定义在线程池中)*/
    void threadFunc();
private:
    /*存放线程对象的列表*/
    std::vector<std::unique_ptr<CThreadObj>> threads_;

    /*初始时刻，线程池中线程的数量*/
    unsigned int initThreadSize_;

    /*存放线程对象需要执行的任务的队列*/
    std::queue<std::shared_ptr<CThreadTask>> taskQueue_;

    /*当前任务队列中，任务的数量*/
    std::atomic_uint taskSize_;

    /*当前队列的最大容量*/
    unsigned int taskQueMaxThreshold_;

    /*任务队列的锁*/
    std::mutex taskQueMtx_;

    /*任务队列不空*/
    std::condition_variable notEmpty_;

    /*任务队列不满*/
    std::condition_variable notFull_;

    /*当前线程池的模型*/
    TThreadPoolModel poolMode_;
};

#endif // THREADPOOL_H
