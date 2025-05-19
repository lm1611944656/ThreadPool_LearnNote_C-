#include "factory.h"
#include "yoloopencvclassify.h"
#include "yoloopencvdetect.h"
#include "utils/logging.h"

//CYoloFactory::CYoloFactory(){
//    modelRegistration(TModelType::IMG_CLASSIFY, []()->std::unique_ptr<CYoloInterface>{return std::make_unique<CYoloOpencvClassify>();});
//    modelRegistration(TModelType::IMG_DETECT, []()->std::unique_ptr<CYoloInterface>{return std::make_unique<CYoloOpenCVDetect>();});
//}

CYoloFactory::~CYoloFactory(){

}

void CYoloFactory::modelRegistration(const TModelType &modelType, pFunc modelObj)
{
    modelList[modelType] = modelObj;
}

std::unique_ptr<CYoloInterface>
CYoloFactory::createModel(const TModelType &modelType)
{
    /**查表法，查找需要创建的算法 */
    std::map<TModelType, pFunc>::iterator it;
    it = modelList.find(modelType);
    if (it == modelList.end()) {
        NN_LOG_ERROR("The algorithm you want is not registered !");
        throw std::runtime_error("Algorithm type not registered!");
    }
    return it->second();
}
