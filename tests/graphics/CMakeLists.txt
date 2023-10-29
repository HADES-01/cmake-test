project(graphics)
add_executable(${PROJECT_NAME} tester.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${LIBS_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

add_test(NAME "GRAPHICS.TEST.1" COMMAND "graphics")
