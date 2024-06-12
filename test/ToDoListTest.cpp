
#include <gtest/gtest.h>
#include "../ToDoList.h"
#include <sstream>
#include <fstream>

class ToDoListTest : public ::testing::Test {
protected:
    ToDoList todoList;
    std::string tempFilename;

    ToDoListTest() {
        tempFilename = "temp_tasks.txt";
        std::ofstream tempFile(tempFilename); //creates a temporary file
        tempFile.close(); //file is properly created and can be opened by the ToDoList constructor
        todoList = ToDoList(tempFilename);
    }

    ~ToDoListTest() override {
        std::remove(tempFilename.c_str()); //removes the temporary file for testing
    }

    void SetUp() override {
        todoList.clearTasks();
    }
};

TEST_F(ToDoListTest, Constructor) {
    EXPECT_TRUE(todoList.getTasks().empty());
}

TEST_F(ToDoListTest, AddTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    EXPECT_EQ(todoList.getTasks().size(), 1);
    EXPECT_EQ(todoList.getTasks()[0]->getTitle(), "Task 1");
}

TEST_F(ToDoListTest, RemoveTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.addTask("Task 2", "Description 2", 1);
    todoList.removeTask("Task 1");
    EXPECT_EQ(todoList.getTasks().size(), 1);
    EXPECT_EQ(todoList.getTasks()[0]->getTitle(), "Task 2");
}

TEST_F(ToDoListTest, ModifyTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.modifyTask("Task 1", "New Description");
    EXPECT_EQ(todoList.getTasks()[0]->getDescription(), "New Description");
}

TEST_F(ToDoListTest, MarkAsCompleted) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.markAsCompleted("Task 1");
    EXPECT_TRUE(todoList.getTasks()[0]->isCompleted());
}

TEST_F(ToDoListTest, OrganizeTasks) {
    todoList.addTask("Task 1", "Description 1", 1);
    todoList.addTask("Task 2", "Description 2", 2);
    todoList.organizeTasks();
    EXPECT_EQ(todoList.getTasks()[0]->getPriority(), 1);
    EXPECT_EQ(todoList.getTasks()[1]->getPriority(), 2);
}
