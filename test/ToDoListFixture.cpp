
#include "gtest/gtest.h"
#include "../ToDoList.h"

class ToDoListFixture : public ::testing::Test {
protected:
    void SetUp() override {

        todolist.addTask("Task 1", "Description 1", 2);
        todolist.addTask("Task 2", "Description 2", 1);
        todolist.addTask("Task 3", "Description 3", 3);


        todolist.markAsCompleted("Task 1");
        todolist.markAsCompleted("Task 3");
    }

    void TearDown() override {
        //clear the ToDoList after each test
        todolist.tasks.clear();
    }

    ToDoList todolist{"My ToDoList"};
};

TEST_F(ToDoListFixture, TestDisplayTasks) {

    std::stringstream ss;
    todolist.displayTasks([&](const ToDo& task) { ss << task.getTitle() << " - " << task.getDescription() << std::endl; return true; });

    EXPECT_EQ(ss.str(), "Task 2 - Description 2\nTask 1 - Description 1\nTask 3 - Description 3\n");
}

TEST_F(ToDoListFixture, TestDisplayCompletedTasks) {

    std::stringstream ss;
    todolist.displayTasks([&](const ToDo& task) { ss << task.getTitle() << " - " << task.getDescription() << std::endl; return task.isCompleted(); });

    EXPECT_EQ(ss.str(), "Task 1 - Description 1\nTask 3 - Description 3\n");
}

TEST_F(ToDoListFixture, TestDisplayUncompletedTasks) {
    //test that only uncompleted tasks are displayed
    std::stringstream ss;
    todolist.displayTasks([&](const ToDo& task) { ss << task.getTitle() << " - " << task.getDescription() << std::endl; return !task.isCompleted(); });

    EXPECT_EQ(ss.str(), "Task 2 - Description 2\n");
}

TEST_F(ToDoListFixture, TestRemoveTask) {

    todolist.removeTask("Task 2");

    std::stringstream ss;
    todolist.displayTasks([&](const ToDo& task) { ss << task.getTitle() << " - " << task.getDescription() << std::endl; return true; });

    EXPECT_EQ(ss.str(), "Task 1 - Description 1\nTask 3 - Description 3\n");
}


TEST_F(ToDoListFixture, TestSaveAndLoad) {

    todolist.saveTasks();

    ToDoList loadedList;
    loadedList.loadTasks();

    std::stringstream ss;
    loadedList.displayTasks([&](const ToDo& task) { ss << task.getTitle() << " - " << task.getDescription() << std::endl; return true; });

    EXPECT_EQ(ss.str(), "Task 2 - Description 2\nTask 1 - Description 1\nTask 3 - Description 3\n");
}
