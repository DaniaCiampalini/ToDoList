
#include "ToDoList.h"
#include <iostream>


ToDoList::ToDoList() : numTasks(0), tasks{} {}  //constructor


//TODO this method should throw an exception if the ToDoList is already full.
void ToDoList::addTask(const ToDo &task) {
    if (numTasks < MAX_SIZE) {
        tasks[numTasks] = task;
        numTasks++;
    } else {
        std::cerr << "Error: ToDoList is full." << std::endl;
    }
}


//TODO it should throw an exception if the specified title is not found in the ToDoList.
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


//TODO it should throw an exception if the specified title is not found in the ToDoList.
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


//TODO it should throw an exception if the specified title is not found in the ToDoList.
void ToDoList::markAsCompleted(const std::string& title) {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].getDescription() == title) {
            tasks[i].setCompleted(true);
            return;
        }
    }
    std::cout << "Task not found." << std::endl;
}


//TODO implement organizeTasks in a more efficient way (bubble sort has a time complexity of O(n^2))
void ToDoList::organizeTasks() {
    for (int i = 0; i < numTasks; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[j].getPriority() < tasks[minIndex].getPriority()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            ToDo tmp = tasks[i];
            tasks[i] = tasks[minIndex];
            tasks[minIndex] = tmp;
        }
    }
}


int ToDoList::findTaskIndex(const std::string &title) const {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].getTitle() == title) {
            return i;
        }
    }
    return -1;
}
