#include <iostream>

#if 0
#include <memory>
#include "yolointerface.h"
#include "yoloopencvclassify.h"
#include "yoloopencvdetect.h"
int main() {
    std::unique_ptr<CYoloInterface> yoloClassify = std::make_unique<CYoloOpencvClassify>();
    yoloClassify->modelInference();

    std::cout << "******************" << std::endl;

    std::unique_ptr<CYoloInterface> yoloDetect = std::make_unique<CYoloOpenCVDetect>();
    yoloDetect->modelInference();
    return 0;
}
#endif

#if 1
#include <memory>

#include "factory.h"
#include "yolointerface.h"

int main(int argc, char **argv){
    try{
        /*创建一个工程*/
        //std::unique_ptr<CYoloFactory> yoloFactory = std::make_unique<CYoloFactory>();
        // 获取工厂单例实例（通过智能指针）
        std::shared_ptr<CYoloFactory> yoloFactory = CYoloFactory::GetInstance();

        /*利用工厂创建一个分类模型*/
        std::unique_ptr<CYoloInterface> yoloClassify;
        yoloClassify = yoloFactory->createModel(TModelType::IMG_CLASSIFY);
        yoloClassify->modelInference();

        std::cout << "*************************" << std::endl;

        /*利用工厂创建一个检测模型*/
        std::unique_ptr<CYoloInterface> yoloDetect = yoloFactory->createModel(IMG_DETECT);
        yoloDetect->modelInference();

        std::cout << "*************************" << std::endl;

        /*再次创建一个检测模型*/
        std::shared_ptr<CYoloInterface> yoloDetect2 = yoloFactory->createModel(IMG_DETECT);
        yoloDetect2->modelInference();

        /*创建一个没有注册的模型*/
//        std::unique_ptr<CYoloInterface> obj;
//        obj = yoloFactory->createModel(MODEL_TYPE_SIZE);
    }  catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
#endif
