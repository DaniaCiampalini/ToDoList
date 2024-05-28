add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES runAllTests.cpp ToDoListExceptionTest.cpp ToDoTest.cpp ToDoListFixture.cpp ToDoListTest.cpp)

add_executable(my_test ${SOURCE_TEST_FILES})

target_link_libraries(my_test gtest gtest_main core)
