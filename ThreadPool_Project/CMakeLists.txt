cmake_minimum_required(VERSION 3.23)
project(ThreadPool_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(ThreadPool_Project main.cpp
        threadpool.cpp
        threadpool.h)
