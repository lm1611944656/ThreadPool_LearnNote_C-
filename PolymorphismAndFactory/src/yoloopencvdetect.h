#ifndef YOLOOPENCVDETECT_H
#define YOLOOPENCVDETECT_H

#include "yolointerface.h"
#include "factory.h"

class CYoloOpenCVDetect : public CYoloInterface {
public:
    explicit CYoloOpenCVDetect();
    ~CYoloOpenCVDetect();

    void modelInference() override;
private:
    void init() override;
    void pre_process() override;
    void inference() override;
    void post_process() override;
};

REGISTER_ALGO(TModelType::IMG_DETECT, CYoloOpenCVDetect);

#endif // YOLOOPENCVDETECT_H
