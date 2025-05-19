#if 0
#include "threadpool.h"
#include <iostream>

// 一个简单的函数，返回传入整数的平方
int square(int num) {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时操作
    return num * num;
}

int main() {
    // 创建一个包含4个线程的线程池
    ThreadPool pool(4);

    // 准备存放future的容器
    std::vector<std::future<int>> futures;

    // 向线程池中添加任务并获取future用于获取结果
    for (int i = 0; i < 10; ++i) {
        futures.emplace_back(pool.enqueue(&square, i));
    }

    // 输出每个任务的结果
    for(auto &future : futures) {
        // get()会等待直到对应的task完成
        std::cout << "Square: " << future.get() << std::endl;
    }

    return 0;
}
#endif

#include <iostream>
#include <thread>
#include "threadpool.h"

class MyClass {
public:
    MyClass(int id) : id_(id) {}

    int computeSquare(int x) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Thread ID: " << id_ << " computing square of " << x << std::endl;
        return x * x;
    }

private:
    int id_;
};

int main() {
    ThreadPool pool(4);

    MyClass obj(1256); // 创建一个类实例

    // 提交成员函数到线程池
    auto futureResult = pool.enqueue(&MyClass::computeSquare, &obj, 5);

    // 等待并获取结果
    int result = futureResult.get();

    std::cout << "Final Result: " << result << std::endl;

    return 0;
}

// https://blog.csdn.net/f110300641/article/details/83475597