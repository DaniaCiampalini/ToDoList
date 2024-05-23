#include "ToDoList.h"
#include <algorithm>
#include <iostream>
#include <memory>

ToDoList::ToDoList() = default;

void ToDoList::addTask(std::string title, std::string description, int priority) {
    std::unique_ptr<ToDo> newTask = std::unique_ptr<ToDo>(new ToDo(std::move(title), std::move(description), priority));
    tasks.push_back(std::move(newTask));
}

void ToDoList::removeTask(const std::string& title) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [&](const std::unique_ptr<ToDo>& task) { return task->getTitle() == title; }), tasks.end());
}

void ToDoList::modifyTask(const std::string& title, const std::string& newDescription) {
    for (auto& task : tasks) {
        if (task->getTitle() == title) {
            task->modifyDescription(newDescription);
            return;
        }
    }
    std::cerr << "Error: Task not found." << std::endl;
}

void ToDoList::displayTasks(const std::function<bool(const ToDo&)>& filter) const {
    for (const auto& task : tasks) {
        if (filter(*task)) {
            task->display();
        }
    }
}

void ToDoList::displayTasksByPriority() {
    std::sort(tasks.begin(), tasks.end(), [](const std::unique_ptr<ToDo>& a, const std::unique_ptr<ToDo>& b) {
        return a->getPriority() > b->getPriority();
    });
    displayTasks([](const ToDo& task) { return task.getPriority() > 0; });
}

void ToDoList::markAsCompleted(const std::string& title) {
    for (auto& task : tasks) {
        if (task->getTitle() == title) {
            task->markAsCompleted();
            return;
        }
    }
    std::cerr << "Error: Task not found." << std::endl;
}

void ToDoList::organizeTasks() {
    std::sort(tasks.begin(), tasks.end(), [](const std::unique_ptr<ToDo>& a, const std::unique_ptr<ToDo>& b) {
        return a->getPriority() > b->getPriority();
    });
}
