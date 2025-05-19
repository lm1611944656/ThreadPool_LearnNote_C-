cmake_minimum_required(VERSION 3.23)
project(test20250512)

set(CMAKE_CXX_STANDARD 17)

add_executable(test20250512 main.cpp yolo.cpp Yolo_OpenCV.cpp Yolo_TensorRT.cpp)
