#include <iostream>
#include <chrono>
#include "threadpool.h"

class MyTask : public CThreadTask{
    void run() override{
        std::cout << "Thread Id: "
                  << std::this_thread::get_id()
                  << " Begin run."
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Thread Id: "
                  << std::this_thread::get_id()
                  << " End run."
                  << std::endl;
    }
};

class MyTask2 : public CThreadTask{
    void run() override{
        std::cout << "Thread Id: "
                  << std::this_thread::get_id()
                  << " Begin run."
                  << std::endl;

        printf("22222\n\r");
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Thread Id: "
                  << std::this_thread::get_id()
                  << " End run."
                  << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    CThreadPool poolObj;
    poolObj.setMode(MODE_FIXED);
    poolObj.start(4);

    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());
    poolObj.submitTask(std::make_shared<MyTask>());

    poolObj.submitTask(std::make_shared<MyTask2>());
    poolObj.submitTask(std::make_shared<MyTask2>());
    poolObj.submitTask(std::make_shared<MyTask2>());
    poolObj.submitTask(std::make_shared<MyTask2>());

    getchar();
    return 0;
}
