cmake_minimum_required(VERSION 3.23)
project(application)

set(CMAKE_CXX_STANDARD 14)

add_executable(application
        src/main.cpp
        src/yolointerface.cpp
        src/yoloopencvclassify.cpp
        src/yoloopencvdetect.cpp
        src/factory.cpp)
