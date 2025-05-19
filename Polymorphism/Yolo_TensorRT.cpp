#include "Yolo_TensorRT.h"
#include <iostream>

void Yolo_TensorRT::init() {
    /*使用TensorRT的接口函数执行前向传播*/
    std::cout << "Yolo_TensorRT::init()" << std::endl;
}

void Yolo_TensorRT::pre_process(){
    /*使用TensorRT的接口函数执行图像预处理*/
    std::cout << "Yolo_TensorRT::pre_process()" << std::endl;
}

void Yolo_TensorRT::forwardPropagation() {
    /*使用TensorRT的接口函数执行模型的前向传播*/
    std::cout << "Yolo_TensorRT::forwardPropagation()" << std::endl;
}

void Yolo_TensorRT::post_process(){
    /*使用TensorRT的接口函数对模型的输出进行后处理*/
    std::cout << "Yolo_TensorRT::post_process()" << std::endl;
}