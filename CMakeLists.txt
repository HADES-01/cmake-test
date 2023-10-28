cmake_minimum_required(VERSION 3.27.1)
set( CMAKE_CXX_COMPILER "g++.exe" )
set( CMAKE_C_COMPILER "gcc.exe" )
project(SOLID)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Human)
add_subdirectory(ext/glfw)


target_link_directories(${PROJECT_NAME} 
    PRIVATE Human 
    PRIVATE ext/glfw/src
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Human 
    PUBLIC ext/glfw/include
)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} Human glfw OpenGL::GL)