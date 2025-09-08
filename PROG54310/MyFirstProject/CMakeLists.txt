cmake_minimum_required(VERSION 3.31)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyFirstProject MyFirstProject/MyFirstProject.cpp)

find_package(GLEW REQUIRED)
target_link_libraries(MyFirstProject GLEW::GLEW)
find_package(glfw3 REQUIRED)
target_link_libraries(MyFirstProject glfw)
include_directories("./External/glm")