add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/googletest)
set(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/lib")

set(builtin_glew ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

set(SOURCE_TEST_FILES
        runAllTests.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../ToDo.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../ToDoList.cpp
        ToDoListExceptionTest.cpp
        ToDoTest.cpp
        ToDoListTest.cpp
)

add_executable(my_test ${SOURCE_TEST_FILES})

target_link_libraries(my_test gtest gtest_main)
