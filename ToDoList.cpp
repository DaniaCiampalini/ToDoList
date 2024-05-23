
#include "ToDoList.h"
#include <algorithm>
#include <iostream>
#include <utility>

ToDoList::ToDoList(std::string filename) : filename(std::move(filename)) {
    loadTasks();
}

void ToDoList::addTask(std::string title, std::string description, int priority) {
    std::unique_ptr<ToDo> newTask = std::unique_ptr<ToDo>(new ToDo(std::move(title), std::move(description), priority));
    tasks.push_back(std::move(newTask));
    saveTasks();
}

void ToDoList::removeTask(const std::string& title) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
                               [&](const std::unique_ptr<ToDo>& task) { return task->getTitle() == title; }), tasks.end());
    saveTasks();
}

void ToDoList::modifyTask(const std::string& title, const std::string& newDescription) {
    for (auto& task : tasks) {
        if (task->getTitle() == title) {
            task->modifyDescription(newDescription);
            saveTasks();
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
            saveTasks();
            return;
        }
    }
    std::cerr << "Error: Task not found." << std::endl;
}

void ToDoList::organizeTasks() {
    std::sort(tasks.begin(), tasks.end(), [](const std::unique_ptr<ToDo>& a, const std::unique_ptr<ToDo>& b) {
        return a->getPriority() > b->getPriority();
    });
    saveTasks();
}


/*The 'saveTasks' method is used to save the current state of the ToDoList to a file.
 * It opens a file with the name specified in the filename member variable using a std::ofstream object.*/
void ToDoList::saveTasks() {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file to save tasks." << std::endl;
        return;
    }
    for (const auto& task : tasks) {
        outfile << task->getTitle() << ',' << task->getDescription() << ',' << task->getPriority() << ',' << (task->isCompleted() ? "1" : "0") << '\n';
    }
}

/*The 'loadTasks' function is used to load tasks from a file into the ToDoList.
 * It opens a file with the name specified in the filename member variable using a std::ifstream object. */
void ToDoList::loadTasks() {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string title, description;
        int priority;
        std::string completed;
        std::getline(iss, title, ',');
        std::getline(iss, description, ',');
        iss >> priority;
        std::getline(iss, completed, ',');
        addTask(std::move(title), std::move(description), priority);
        if (!tasks.empty()) {
            tasks.back()->markAsCompleted();
        }
    }
}
