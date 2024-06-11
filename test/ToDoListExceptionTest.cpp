
#include <gtest/gtest.h>
#include "../ToDoListException.h"

class ToDoListExceptionTest : public ::testing::Test {
};

TEST_F(ToDoListExceptionTest, Constructor) {
    ToDoListException e("Error message");
    EXPECT_EQ(std::string(e.what()), "Error message");
}