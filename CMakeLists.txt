cmake_minimum_required(VERSION 3.18)
project(ToDoList)

set(CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES ToDo.cpp ToDo.h ToDoList.cpp ToDoList.h ToDoListException.h)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)