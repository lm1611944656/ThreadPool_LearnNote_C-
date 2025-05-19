#ifndef YOLOINTERFACE_H
#define YOLOINTERFACE_H

#include <iostream>

typedef enum{
    IMG_CLASSIFY,           // 图像分类模型
    IMG_DETECT,             // 图像检测模型
    MODEL_TYPE_SIZE         // 模型数量
}TModelType;

class CYoloInterface {
public:
    CYoloInterface();
    ~CYoloInterface();
public:
    /*模型推理*/
    //void modelInference(void);
    virtual void modelInference() = 0;

private:
    /**/
    virtual void init(void) = 0;

    /*预处理*/
    virtual void pre_process(void) = 0;

    /*前向传播*/
    virtual void inference(void) = 0;

    /*后处理*/
    virtual void post_process(void);
};

#endif // YOLOINTERFACE_H
