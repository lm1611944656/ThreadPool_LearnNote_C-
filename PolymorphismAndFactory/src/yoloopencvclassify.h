#ifndef YOLOOPENCVCLASSIFY_H
#define YOLOOPENCVCLASSIFY_H

#include "yolointerface.h"
#include "factory.h"

class CYoloOpencvClassify : public CYoloInterface {

public:
    explicit CYoloOpencvClassify();
    ~CYoloOpencvClassify();

    void modelInference() override;
private:
    void init() override;
    void pre_process() override;
    void inference() override;
    void post_process(void) override;
};
REGISTER_ALGO(TModelType::IMG_CLASSIFY, CYoloOpencvClassify);

#endif // YOLOOPENCVCLASSIFY_H
