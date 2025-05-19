#include "yolo.h"

void Yolo::model_inference(){
    std::cout << "Yolo::model_inference()" << std::endl;
    /**1.读取图像*/
    srcImg = 10;

    /**2.图像预处理*/
    pre_process();

    /**3.模型前向传播 */
    forwardPropagation();

    /**4.后处理*/
    post_process();
}

void Yolo::post_process() {
    std::cout << "Yolo::post_process()" << std::endl;
}