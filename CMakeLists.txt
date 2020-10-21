cmake_minimum_required(VERSION 3.17)
project(101_lab3)

set(CMAKE_CXX_STANDARD 17)
include_directories("E:/CLion-library/eigen-3.3.7")
set(OpenCV_DIR E:/opencv3/opencv/mingw-build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})



add_executable(101_lab3 main.cpp rasterizer.hpp rasterizer.cpp global.hpp Triangle.hpp Triangle.cpp Texture.hpp Texture.cpp Shader.hpp OBJ_Loader.h)
target_link_libraries(101_lab3 ${OpenCV_LIBS})