#ifndef YOLO_TENSORRT_H
#define YOLO_TENSORRT_H

#include "yolo.h"

class Yolo_TensorRT : public Yolo{
public:
    void init() override;
    void pre_process() override;
    void forwardPropagation() override;
    void post_process() override;
};

#endif // YOLO_TENSORRT_H
