
#include "ToDo.h"
#include <iostream>

ToDo::ToDo(std::string title, std::string description, int priority)
        : title(std::move(title)), description(std::move(description)), priority(priority), completed(false) {}

const std::string& ToDo::getTitle() const {
    return title;
}

const std::string& ToDo::getDescription() const {
    return description;
}

int ToDo::getPriority() const {
    return priority;
}

void ToDo::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void ToDo::modifyDescription(const std::string& newDescription) {
    description = newDescription;
}

void ToDo::setPriority(int newPriority) {
    priority = newPriority;
}

void ToDo::markAsCompleted() {
    completed = true;
}

bool ToDo::isCompleted() const {
    return completed;
}

void ToDo::display() const {
    std::cout << "Title: " << title << "\nDescription: " << description;
    std::cout << "\nPriority: " << priority << "\nCompleted: " << (completed ? "Yes" : "No") << std::endl;
}
