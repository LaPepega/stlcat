cmake_minimum_required(VERSION 4.0)
project(stlcat)

include_directories(include)

add_library(stl3d src/stl3d.c)
add_library(vec3 src/vec3.c)

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.c)
target_link_libraries(${PROJECT_NAME} stl3d vec3 m)
