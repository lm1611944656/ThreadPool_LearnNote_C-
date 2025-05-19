#include <iostream>
#include "Yolo_OpenCV.h"
#include "Yolo_TensorRT.h"
#include <memory>

/*单线程操作*/
#if 0
int main() {

    /**使用智能指针创建 Yolo_OpenCV 对象 */
    std::unique_ptr<Yolo> opencv = std::make_unique<Yolo_OpenCV>();
    opencv->init();
    opencv->model_inference();

    std::cout << "************************************" << std::endl;

    /**创建一个Yolo_TensorRT对象 */
    std::unique_ptr<Yolo> tensorRT = std::make_unique<Yolo_TensorRT>();
    tensorRT->init();
    tensorRT->model_inference();
    return 0;
}
#endif

/*多线程操作*/
#if 1
#include <thread>

void timeConsumingOperation(std::unique_ptr<Yolo> yolo)
{
    yolo->init();
    yolo->model_inference();
}

int main()
{
    // 启动两个线程分别运行不同的模型
    std::thread t1(timeConsumingOperation, std::make_unique<Yolo_OpenCV>());
    std::thread t2(timeConsumingOperation, std::make_unique<Yolo_TensorRT>());

    // 等待线程完成
    t1.join();
    t2.join();

    std::cout << "All models finished." << std::endl;
    return 0;
}
#endif