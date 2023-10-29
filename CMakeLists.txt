cmake_minimum_required(VERSION 3.27.1)
set( CMAKE_CXX_COMPILER "g++.exe" )
set( CMAKE_C_COMPILER "gcc.exe" )

# Versioning inside project() command 
# (PROJECT_NAME)_VERSION_MAJOR.(PROJECT_NAME)_VERSION_MINOR
project(cmake VERSION 1.3)

# creating an option to include Human Library or not.
# defaults to ON
option(USE_HUMAN "Basic Library" OFF)
option(USE_GRAPHICS "Graphics Library" OFF)
option(TEST "Start TESTING" OFF)

if(TEST) 
    set(USE_HUMAN ON)
    set(USE_GRAPHICS ON)
endif()

if(USE_HUMAN)
    # # adding HUMAN library only if the USE_HUMAN is ON
    add_subdirectory(Human)
    list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/Human")
    list(APPEND LIB_DIRS "${PROJECT_SOURCE_DIR}/Human")
    list(APPEND LIBS "Human")
endif()


if(USE_GRAPHICS)
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
        
    find_package(OpenGL REQUIRED)
    add_subdirectory(ext/glfw)
    add_subdirectory(ext/glad)
    add_subdirectory(ext/glew-cmake/build/cmake)
    list(APPEND LIB_DIRS 
        "${PROJECT_SOURCE_DIR}/ext/glfw/src" 
        "${PROJECT_SOURCE_DIR}/ext/glew-cmake/src"
        "${PROJECT_SOURCE_DIR}/ext/glad/src"
    )
    list(APPEND INCLUDE_DIRS 
        "${PROJECT_SOURCE_DIR}/ext/glfw/include"
        "${PROJECT_SOURCE_DIR}/ext/glfw/deps"
        "${PROJECT_SOURCE_DIR}/ext/glew-cmake/include"
        "${PROJECT_SOURCE_DIR}/ext/glad/include"
    )
    list(APPEND LIBS "glfw" "OpenGL::GL" "glew" "glad")
endif()
        
if(TEST) 
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

list(APPEND INCLUDE_DIRS "ext/boost")

if(NOT TEST)
    # Points to the main file to be compiled
    add_executable(${PROJECT_NAME} main.cpp)
    # # configure_file that has access to all the cmake variables
    configure_file(cmake.h.in cmake.h)
    # # include the compiled configure file to final build
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
    target_link_directories(${PROJECT_NAME} PRIVATE ${LIB_DIRS})
    target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${LIBS})
endif()


# # setting some basic options for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(InstallRequiredSystemLibraries)
include(CPack)