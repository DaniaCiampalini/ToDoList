
#include "ToDoList.h"
#include <algorithm>
#include <iostream>

ToDoList::ToDoList() = default;

void ToDoList::addTask(const std::string& title, const std::string& description, int priority) {
    tasks.emplace_back(title, description, priority);
}

void ToDoList::removeTask(const std::string& title) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [&](const ToDo& task) { return task.getTitle() == title; }), tasks.end());
}

void ToDoList::modifyTask(const std::string& title, const std::string& newDescription) {
    int index = findTaskIndex(title);

    if (index != -1) {
        tasks[index].modifyDescription(newDescription);
    } else {
        std::cerr << "Error: ToDo not found." << std::endl;
    }
}

void ToDoList::displayTasks() const {
    for (const auto& task : tasks) {
        task.display();
    }
}

void ToDoList::displayCompletedTasks() const {
    for (const auto& task : tasks) {
        if (task.isCompleted()) {
            task.display();
        }
    }
}

void ToDoList::displayUncompletedTasks() const {
    for (const auto& task : tasks) {
        if (!task.isCompleted()) {
            task.display();
        }
    }
}

void ToDoList::displayTasksByPriority() {
    std::sort(tasks.begin(), tasks.end(), [](const ToDo& a, const ToDo& b) {
        return a.getPriority() > b.getPriority();
    });
    displayTasks();
}

void ToDoList::markAsCompleted(const std::string& title) {
    int index = findTaskIndex(title);
    if (index != -1) {
        tasks[index].markAsCompleted();
    } else {
        std::cerr << "Error: Task not found." << std::endl;
    }
}

int ToDoList::findTaskIndex(const std::string& title) const {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].getTitle() == title) {
            return i;
        }
    }
    return -1;
}

void ToDoList::organizeTasks() {
    std::sort(tasks.begin(), tasks.end(), [](const ToDo& a, const ToDo& b) {
        return a.getPriority() > b.getPriority();
    });
}
