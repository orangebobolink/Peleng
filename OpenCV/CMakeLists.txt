cmake_minimum_required(VERSION 3.12)
project(OpenCV)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "D:/opencv/build")

find_package(OpenCV REQUIRED)

add_executable(OpenCV main.cpp)

target_include_directories(OpenCV PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(OpenCV ${OpenCV_LIBS})