
#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "ToDo.h"

class ToDoList {
public:
    ToDoList();

    void addTask(const ToDo& task);
    void removeTask(const std::string& title);
    void modifyTask(const std::string& title, const std::string& newDescription);

    void displayTasks() const;
    void displayCompletedTasks() const;
    void displayUncompletedTasks() const;

    void displayTasksByPriority();

    void markAsCompleted(const std::string& title);
    void organizeTasks();

private:
    std::vector<ToDo> tasks;   //std::vector provides faster random access to elements

    int findTaskIndex(const std::string& title) const;
    void removeTaskAtIndex(int index);
};

#endif //TODOLIST_H
