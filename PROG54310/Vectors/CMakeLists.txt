cmake_minimum_required(VERSION 3.31)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project
        Vectors/Vectors.cpp
        Vectors/obj.cpp
        Vectors/Matrix.cpp
        Vectors/Matrix.h
)

find_package(GLEW REQUIRED)
target_link_libraries(project GLEW::GLEW)
find_package(glfw3 REQUIRED)
target_link_libraries(project glfw)
include_directories("./External/glm")