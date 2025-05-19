#ifndef YOLO_OPENCV_H
#define YOLO_OPENCV_H

#include "yolo.h"

class Yolo_OpenCV : public Yolo {
public:
    void init() override;
    void pre_process() override;
    void forwardPropagation() override;
};

#endif /*YOLO_OPENCV_H */