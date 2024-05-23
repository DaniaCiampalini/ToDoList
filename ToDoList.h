
#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <vector>
#include "ToDo.h"
#include <functional>
#include <memory>

class ToDoList {
public:
    ToDoList();

    void addTask(std::string title, std::string description = "", int priority = 1);
    void removeTask(const std::string& title);
    void modifyTask(const std::string& title, const std::string& newDescription);

    void displayTasks(const std::function<bool(const ToDo&)>& filter = [](const ToDo&) { return true; }) const;
    void displayTasksByPriority();

    void markAsCompleted(const std::string& title);
    void organizeTasks();

private:
    std::vector<std::unique_ptr<ToDo>> tasks;
};

#endif //TODOLIST_TODOLIST_H