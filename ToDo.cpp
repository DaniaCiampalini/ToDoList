
#include "ToDo.h"

ToDo::ToDo() : completed(false) {}
ToDo::ToDo(std::string title, std::string description) : ToDo() {
    title = std::move(title);
    description = std::move(description);
}

const std::string& ToDo::getTitle() const {
    return title;
}

const std::string& ToDo::getDescription() const {
    return description;
}

void ToDo::setTitle(std::string newTitle) {
    title = std::move(newTitle);
}

void ToDo::modifyDescription(const std::string &newDescription) {
    description = std::move(newDescription);
}

void ToDo::markAsCompleted() {
    completed = true;
}

bool ToDo::isCompleted() const {
    return completed;
}

void ToDo::setCompleted(bool isCompleted) {
    completed = isCompleted;
}
