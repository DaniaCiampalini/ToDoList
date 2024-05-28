
#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "ToDo.h"
#include <functional>
#include <memory>
#include <fstream>
#include <sstream>

class ToDoList {
public:
    explicit ToDoList(std::string  filename = "tasks.txt");

    void addTask(const std::string& title, const std::string& description, int priority);
    void removeTask(const std::string& title);
    void modifyTask(const std::string& title, const std::string& newDescription);

    void displayTasks(const std::function<bool(const ToDo&)>& filter = [](const ToDo&) { return true; }) const;
    void displayTasksByPriority();

    void markAsCompleted(const std::string& title);
    void organizeTasks();

    void saveTasks();
    void loadTasks();

    std::vector<std::unique_ptr<ToDo> > tasks;

private:
    std::string filename;
};

#endif //TODOLIST_TODOLIST_H