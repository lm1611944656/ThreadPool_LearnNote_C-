#ifndef YOLO_H
#define YOLO_H
#include <iostream>

class Yolo {
public:
    void model_inference();

    /*声明纯虚函数(派生类中必须实现该函数)*/
    virtual void init() = 0;
private:
    /*声明纯虚函数(派生类中必须实现该函数)*/
    virtual void pre_process() = 0;

    /*声明纯虚函数(派生类中必须实现该函数)*/
    virtual void forwardPropagation() = 0;

    /*非纯虚函数，有默认实现; 如果派生类中重写就用派生类的，如果派生类不重写只能走基类的*/
    virtual void post_process();
protected:
    int srcImg{};
};

#endif // YOLO_H