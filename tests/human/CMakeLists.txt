project(human)
add_executable(${PROJECT_NAME} tester.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${LIB_DIRS})
target_link_libraries(${PROJECT_NAME} ${LIBS})

add_test(NAME "Human.Test" COMMAND "human" 2 aditya WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "Human.Test3" COMMAND "human" 3 temp WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
