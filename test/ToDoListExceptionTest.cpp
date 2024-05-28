
#include <gtest/gtest.h>
#include "../ToDoListException.h"

TEST(ToDoListExceptionTest, Constructor) {
    ToDoListException e("Error message");
    EXPECT_EQ(std::string(e.what()), "Error message");
}
