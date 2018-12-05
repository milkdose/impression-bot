cmake_minimum_required(VERSION 2.8)

project(ImpressionBot)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(OpenCV_DIR "/home/test/Documents/share/OpenCV")

add_executable(ImpressionBot ProductList.h ImpressionVisualBot.cpp ProductList.cpp turnToAlpha.cpp)

find_package(OpenCV REQUIRED)
target_link_libraries(ImpressionBot ${OpenCV_LIBS})
