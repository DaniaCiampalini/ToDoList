
#include <gtest/gtest.h>
#include "../ToDo.h"

class ToDoTest : public ::testing::Test {
};

TEST_F(ToDoTest, Constructor) {
    ToDo todo("Task 1", "Description 1", 2);
    EXPECT_EQ(todo.getTitle(), "Task 1");
    EXPECT_EQ(todo.getDescription(), "Description 1");
    EXPECT_EQ(todo.getPriority(), 2);
    EXPECT_FALSE(todo.isCompleted());
}

TEST_F(ToDoTest, Setters) {
    ToDo todo("Task 1", "Description 1", 2);
    todo.setTitle("New Title");
    EXPECT_EQ(todo.getTitle(), "New Title");
    todo.modifyDescription("New Description");
    EXPECT_EQ(todo.getDescription(), "New Description");
    todo.setPriority(3);
    EXPECT_EQ(todo.getPriority(), 3);
}

TEST_F(ToDoTest, MarkAsCompleted) {
    ToDo todo("Task 1", "Description 1", 2);
    todo.markAsCompleted();
    EXPECT_TRUE(todo.isCompleted());
}
