
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
    EXPECT_TRUE(todoList.getTotalTasks() == 0);
}

TEST_F(ToDoListTest, AddTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    EXPECT_EQ(todoList.getTaskAt(0).getTitle(), "Task 1");
}

TEST_F(ToDoListTest, RemoveTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.addTask("Task 2", "Description 2", 1);
    todoList.removeTask("Task 1");
    EXPECT_EQ(todoList.getTaskAt(0).getTitle(), "Task 2");
}

TEST_F(ToDoListTest, ModifyTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.modifyTask("Task 1", "New Description");
    EXPECT_EQ(todoList.getTaskAt(0).getDescription(), "New Description");
}

TEST_F(ToDoListTest, MarkAsCompleted) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.markAsCompleted("Task 1");
    EXPECT_TRUE(todoList.getTaskAt(0).isCompleted());
}

TEST_F(ToDoListTest, ModifyPriority) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.modifyPriority("Task 1", 3);
    EXPECT_EQ(todoList.getTaskAt(0).getPriority(), 3);
}

TEST_F(ToDoListTest, SaveTasks) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.saveTasks();
    std::ifstream file(tempFilename);
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Task 1,Description 1,2,0");
}

TEST_F(ToDoListTest, LoadTasks) {
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.saveTasks();
    ToDoList loadedList(tempFilename);
    EXPECT_EQ(loadedList.getTotalTasks(), 1);
    EXPECT_EQ(loadedList.getTaskAt(0).getTitle(), "Task 1");
}

TEST_F(ToDoListTest, DisplayTasks) {
    testing::internal::CaptureStdout();
    todoList.addTask("Task 2", "Description 2", 1);
    todoList.addTask("Task 1", "Description 1", 2);
    todoList.addTask("Task 3", "Description 3", 1);
    todoList.addTask("Task 4", "Description 4", 5);
    todoList.displayTasksByPriority();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Title: Task 4\n"
                      "Description: Description 4\n"
                      "Priority: 5\n"
                      "Completed: No\n"
                      "Title: Task 1\n"
                      "Description: Description 1\n"
                      "Priority: 2\n"
                      "Completed: No\n"
                      "Title: Task 2\n"
                      "Description: Description 2\n"
                      "Priority: 1\n"
                      "Completed: No\n"
                      "Title: Task 3\n"
                      "Description: Description 3\n"
                      "Priority: 1\n"
                      "Completed: No\n");
}

TEST_F(ToDoListTest, FindTask) {
    todoList.addTask("Task 1", "Description 1", 2);
    ToDo* task = todoList.findTask("Task 1");
    ASSERT_TRUE(task!= nullptr);
    EXPECT_EQ(task->getTitle(), "Task 1");
}

TEST_F(ToDoListTest, LoadTasksFromFileThatDoesNotExist) {
    todoList.loadTasks("non_existent_file.txt");
    EXPECT_TRUE(todoList.getTotalTasks() == 0);
}

TEST_F(ToDoListTest, LoadTasksFromFileThatIsEmpty) {
    std::ofstream file("empty_file.txt");
    file.close();
    todoList.loadTasks("empty_file.txt");
    EXPECT_TRUE(todoList.getTotalTasks() == 0);
    std::remove("empty_file.txt");
}