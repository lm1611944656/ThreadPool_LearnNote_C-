#include "yoloopencvclassify.h"

CYoloOpencvClassify::CYoloOpencvClassify()
{

}

CYoloOpencvClassify::~CYoloOpencvClassify()
{

}

void CYoloOpencvClassify::modelInference(){
    std::cout << "CYoloOpencvClassify::modelInference()" << std::endl;
    pre_process();
    inference();
    post_process();
}

void CYoloOpencvClassify::init(){
    std::cout << "CYoloOpencvClassify::init()" << std::endl;
}

void CYoloOpencvClassify::pre_process(){
    std::cout << "CYoloOpencvClassify::pre_process()" << std::endl;
}

void CYoloOpencvClassify::inference(){
    std::cout << "CYoloOpencvClassify::inference()" << std::endl;
}

void CYoloOpencvClassify::post_process(void) {
    std::cout << "CYoloOpencvClassify::post_process" << std::endl;
}
