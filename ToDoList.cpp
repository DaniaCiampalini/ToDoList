
#include <iostream>
#include "ToDoList.h"


/*Default constructor to ensure that the class
 * can be instantiated without providing any arguments.
 * The default constructor initializes the tasks vector as an empty vector.*/

ToDoList::ToDoList() = default;

void ToDoList::addTask(const ToDo& task) {
    tasks.push_back(task);
}

void ToDoList::removeTask(const std::string& title) {
    int index = findTaskIndex(title);
    if (index != -1) {
        removeTaskAtIndex(index);
    } else {
        std::cerr << "Error: ToDo not found." << std::endl;
    }
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
    std::cout << "Tasks with priority:\n";
    for (int i = 1; i <= 5; i++) {
        std::cout << "Priority: " << i << "\n";
        for (const auto& task : tasks) {
            if (task.getPriority() == i) {
                std::cout << i << ". ";
                task.display();
            }
        }
    }
}

void ToDoList::markAsCompleted(const std::string& title) {
    int index = findTaskIndex(title);
    if (index != -1) {
        tasks[index].markAsCompleted();
    } else {
        std::cerr << "Error: Task not found." << std::endl;
    }
}

void ToDoList::organizeTasks() {
    for (int i = 0; i < tasks.size(); i++) {
        for (int j = i + 1; j < tasks.size();j++) {
            if (tasks[i].getPriority() > tasks[j].getPriority()) {
                std::swap(tasks[i], tasks[j]);
            }
        }
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

void ToDoList::removeTaskAtIndex(int index) {
    tasks.erase(tasks.begin() + index);
}
