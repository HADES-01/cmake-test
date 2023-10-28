cmake_minimum_required(VERSION 3.27.1)
set( CMAKE_CXX_COMPILER "g++.exe" )
set( CMAKE_C_COMPILER "gcc.exe" )

project(cmake VERSION 1.3)
add_executable(${PROJECT_NAME} main.cpp)

configure_file(cmake.h.in cmake.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Human)


find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
   option(GIT_SUBMODULE "Check submodules during build" ON)
   if(GIT_SUBMODULE)
       message(STATUS "Submodule update")
       execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                       WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                       RESULT_VARIABLE GIT_SUBMOD_RESULT)
       if(NOT GIT_SUBMOD_RESULT EQUAL "0")
           message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
       endif()
   endif()
endif()

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