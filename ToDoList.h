
#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "ToDo.h"
#include <functional>
#include <memory>
#include <fstream>
#include <sstream>
#include "ToDoListException.h"
#include <filesystem>

class ToDoList {
public:
    explicit ToDoList(const std::string& filename = "tasks.txt");

    void addTask(const std::string& title, const std::string& description, int priority);
    void removeTask(const std::string& title);
    void modifyTask(const std::string& title, const std::string& newDescription);
    void modifyPriority(const std::string& title, int newPriority);

    void displayTasks(const std::function<bool(const ToDo&)>& filter = [](const ToDo&) { return true; }) const;
    //filter parameter is by default a lambda function so that if no filter is provided, the method will display all tasks
    void displayTasksByPriority();

    void markAsCompleted(const std::string& title);
    void organizeTasks();

    void saveTasks();
    void loadTasks(const std::string& filename);

    //method for clearing the tasks vector directly, using clear()
    void clearTasks() {
        tasks.clear();
    }

    //getter method for test cases to access the tasks
    const std::vector<std::unique_ptr<ToDo>>& getTasks() const { return tasks; }


    ToDo* findTask(const std::string& title);  //made public

private:
    std::string filename;
    std::vector<std::unique_ptr<ToDo>> tasks;

    static std::string getFullPath(const std::string& filename);
};

#endif // TODOLIST_TODOLIST_H