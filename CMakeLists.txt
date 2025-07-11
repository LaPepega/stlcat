cmake_minimum_required(VERSION 4.0)
project(stlcat)

include_directories(include)

set(LIBS vec3 tri solid stlrender)
set(EXTERNAL_LIBS m)

foreach(L IN LISTS LIBS)
    add_library(${L} src/${L}.c)
endforeach()


target_link_libraries(stlrender vec3)


add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.c)
target_link_libraries(${PROJECT_NAME} ${LIBS} ${EXTERNAL_LIBS})
