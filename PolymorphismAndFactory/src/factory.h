#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <map>
#include "yolointerface.h"
#include "./utils/singleton.h"

typedef std::unique_ptr<CYoloInterface> (*pFunc)(void);

class CYoloFactory : public Singleton<CYoloFactory>{
public:
    ~CYoloFactory();

public:
    /*创建模型对象*/
    std::unique_ptr<CYoloInterface> createModel(const TModelType &modelType);

    /*注册模型对象*/
    void modelRegistration(const TModelType &modelType, pFunc modelObj);

private:
    /**单例模式 */
    CYoloFactory() = default; // 私有构造函数
    friend class Singleton<CYoloFactory>;

private:
    /*注册表*/
    std::map<TModelType, pFunc> modelList;
};

#define REGISTER_ALGO(algo_type, algo_class) \
    struct XYZ_##algo_class##_XYZ { \
        XYZ_##algo_class##_XYZ() { \
            CYoloFactory::GetInstance()->modelRegistration( \
                algo_type, \
                []() -> std::unique_ptr<CYoloInterface> { return std::make_unique<algo_class>(); } \
            ); \
        } \
    }; \
    static XYZ_##algo_class##_XYZ algo_class##_ABC;


#endif // FACTORY_H
