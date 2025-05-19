#include "yoloopencvdetect.h"

CYoloOpenCVDetect::CYoloOpenCVDetect(){

}

CYoloOpenCVDetect::~CYoloOpenCVDetect(){

}

void CYoloOpenCVDetect::modelInference() {
    std::cout << "CYoloOpenCVDetect::modelInference()" << std::endl;
    pre_process();
    inference();
}

void CYoloOpenCVDetect::init(){
    std::cout << "CYoloOpenCVDetect::init()" << std::endl;
}

void CYoloOpenCVDetect::pre_process(){
    std::cout << "CYoloOpenCVDetect::pre_process()" << std::endl;
}

void CYoloOpenCVDetect::inference(){
    std::cout << "CYoloOpenCVDetect::inference()" << std::endl;
}

void CYoloOpenCVDetect::post_process(){
    std::cout << "CYoloOpenCVDetect::post_process()" << std::endl;
}
