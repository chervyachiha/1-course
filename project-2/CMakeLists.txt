cmake_minimum_required(VERSION 3.24)
project(2_semestr_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenCV REQUIRED)
include_directories(/opt/homebrew/Cellar/opencv/4.7.0_4/include)
link_directories(/opt/homebrew/Cellar/opencv/4.7.0_4/lib)


add_executable(2_semestr_project main.cpp)


set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_cv)

target_link_libraries(opencv ${OpenCV_LIBS})
