#include "yolointerface.h"

CYoloInterface::CYoloInterface(){

}

CYoloInterface::~CYoloInterface(){

}

/*模型推理*/
//void CYoloInterface::modelInference(void){
//    std::cout << "CYoloInterface::modelInference(void)" << std::endl;
//    this->pre_process();
//    this->inference();
//    this->post_process();
//}

void CYoloInterface::post_process(void){
    std::cout << "CYoloInterface::post_process(void)" << std::endl;
}
