cmake_minimum_required(VERSION 3.27.1)
set( CMAKE_CXX_COMPILER "g++.exe" )
set( CMAKE_C_COMPILER "gcc.exe" )
project(SOLID)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Human)
target_link_directories(${PROJECT_NAME} PRIVATE Human)
target_include_directories(${PROJECT_NAME} PUBLIC Human)
target_link_libraries(${PROJECT_NAME} Human)