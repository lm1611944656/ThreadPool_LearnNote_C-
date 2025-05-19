#include "Yolo_OpenCV.h"
#include <iostream>

void Yolo_OpenCV::init() {
    /*使用OpenCV的接口函数读取图像*/
    std::cout << "Yolo_OpenCV::init()" << std::endl;
}

void Yolo_OpenCV::pre_process() {
    /*使用OpenCV的接口函数预处理图像*/
    std::cout << "Yolo_OpenCV::pre_process()" << std::endl;
    std::cout << "Yolo srcImg = " << srcImg << std::endl;
}

void Yolo_OpenCV::forwardPropagation() {
    /*使用OpenCV的接口函数执行模型的前向传播*/
    std::cout << "Yolo_OpenCV::inference()" << std::endl;
}
