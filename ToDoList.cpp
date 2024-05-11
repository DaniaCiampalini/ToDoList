
#include "ToDoList.h"
#include <iostream>

ToDoList::ToDoList() : numTasks(0), tasks{} {}

void ToDoList::addTask(const ToDo &task) {
    if (numTasks < MAX_SIZE) {
        tasks[numTasks] = task;
        numTasks++;
    } else {
        std::cerr << "Error: ToDoList is full." << std::endl;
    }
}

void ToDoList::removeTask(const std::string &title) {
    int index = findTaskIndex(title);
    if (index != -1) {
        for (int i = index; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;
    } else {
        std::cerr << "Error: ToDo not found." << std::endl;
    }
}

void ToDoList::modifyTask(const std::string &title, const std::string &newDescription) {
    int index = findTaskIndex(title);
    if (index != -1) {
        tasks[index].modifyDescription(newDescription);
    } else {
        std::cerr << "Error: ToDo not found." << std::endl;
    }
}

void ToDoList::displayTasks() const {
    for (int i = 0; i < numTasks; i++) {
        std::cout << "Title: " << tasks[i].getTitle() << ", Description: "
                  << tasks[i].getDescription() << ", Completed: "
                  << (tasks[i].isCompleted() ? "Yes" : "No") << std::endl;
    }
}

void ToDoList::displayUncompletedTasks() const {
    for (int i = 0; i < numTasks; i++) {
        if (!tasks[i].isCompleted()) {
            std::cout << "Title: " << tasks[i].getTitle() << ", Description: "
                      << tasks[i].getDescription() << ", Completed: "
                      << (tasks[i].isCompleted() ? "Yes" : "No") << std::endl;
        }
    }
}


void ToDoList::markAsCompleted(const std::string& title) {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].getDescription() == title) {
            tasks[i].setCompleted(true);
            return;
        }
    }
    std::cout << "Item not found." << std::endl;
}

int ToDoList::findTaskIndex(const std::string &title) const {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].getTitle() == title) {
            return i;
        }
    }
    return -1;
}
