
#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include <iostream>
#include "ToDo.h"

class ToDoList {
public:
    ToDoList();

    void addTask(const ToDo& task);
    void removeTask(const std::string& title);
    void modifyTask(const std::string& title, const std::string& newDescription);

    void displayTasks() const;
    void displayUncompletedTasks() const;

    void markAsCompleted(const std::string& title);
    void organizeTasks();

private:
    static const int MAX_SIZE = 100;
    ToDo tasks[MAX_SIZE];
    int numTasks;

    int findTaskIndex(const std::string& title) const;
};
#endif //TODOLIST_TODOLIST_H
