
#include <gtest/gtest.h>
#include "../ToDoList.h"
#include <sstream>

TEST(ToDoListTest, Constructor) {
    ToDoList todoList("tasks.txt");
    EXPECT_TRUE(todoList.tasks.empty());
}

TEST(ToDoListTest, AddTask) {
    ToDoList todoList("tasks.txt");
    todoList.addTask("Task 1", "Description 1", 2);
    EXPECT_EQ(todoList.tasks.size(), 1);
    EXPECT_EQ(todoList.tasks[0]->getTitle(), "Task 1");
}

TEST(ToDoListTest, RemoveTask) {
    ToDoList todoList("tasks.txt");
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.addTask("Task 2", "Description 2", 1);
    todoList.removeTask("Task 1");
    EXPECT_EQ(todoList.tasks.size(), 1);
    EXPECT_EQ(todoList.tasks[0]->getTitle(), "Task 2");
}

TEST(ToDoListTest, ModifyTask) {
    ToDoList todoList("tasks.txt");
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.modifyTask("Task 1", "New Description");
    EXPECT_EQ(todoList.tasks[0]->getDescription(), "New Description");
}

TEST(ToDoListTest, MarkAsCompleted) {
    ToDoList todoList("tasks.txt");
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.markAsCompleted("Task 1");
    EXPECT_TRUE(todoList.tasks[0]->isCompleted());
}

TEST(ToDoListTest, OrganizeTasks) {
    ToDoList todoList("tasks.txt");
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.addTask("Task 2", "Description 2", 1);
    todoList.organizeTasks();
    EXPECT_EQ(todoList.tasks[0]->getPriority(), 2);
    EXPECT_EQ(todoList.tasks[1]->getPriority(), 1);
}
