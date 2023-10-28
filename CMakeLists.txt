cmake_minimum_required(VERSION 3.27.1)
set( CMAKE_CXX_COMPILER "g++.exe" )
set( CMAKE_C_COMPILER "gcc.exe" )

# Versioning inside project() command 
# (PROJECT_NAME)_VERSION_MAJOR.(PROJECT_NAME)_VERSION_MINOR
project(cmake VERSION 1.3)

# Points to the main file to be compiled
add_executable(${PROJECT_NAME} main.cpp)

# creating an option to include Human Library or not.
# defaults to ON
option(USE_HUMAN "Basic Library" ON)

# adding HUMAN library only if the USE_HUMN is ON
if(USE_HUMAN)
    add_subdirectory(Human)
    # creating a list of include directories
    list(APPEND INCLUDE_DIRS Human)
    #creating a list of Library directories
    list(APPEND LIB_DIRS Human)
    #creating a list of used libraries
    list(APPEND LIBS Human)
endif()

# configure_file that has access to all the cmake variables
configure_file(cmake.h.in cmake.h)
# include the compiled configure file to final build
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# setting some basic options for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


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
    PRIVATE ext/glfw/src
    ${LIB_DIRS} 
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ext/glfw/include
    ${INCLUDE_DIRS}
)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} ${LIBS} glfw OpenGL::GL)

include(InstallRequiredSystemLibraries)
include(CPack)