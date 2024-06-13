
#include "ToDoList.h"
#include <filesystem>
#include <memory>

ToDoList::ToDoList(const std::string& filename) : filename(filename) {  //removed std::move to avoid using moved object
    clearTasks(); //to clear the tasks vector before loading tasks from the file
    loadTasks(filename); //to load the tasks from the file specified by the filename parameter
}

void ToDoList::addTask(const std::string& title, const std::string& description, int priority) {
    if (findTask(title)) {  //before adding a new task, it checks if a task with the same title already exists
        throw ToDoListException("Error: Task with the same title already exists.");
    }
    tasks.push_back(std::make_unique<ToDo>(title, description, priority));  //using make_unique with C++14
    saveTasks();
}

void ToDoList::removeTask(const std::string& title) {
    auto it = std::remove_if(tasks.begin(), tasks.end(), [&](const std::unique_ptr<ToDo>& task) {  //std::remove_if only shifts the elements, erase() needed to remove them
        return task->getTitle() == title;
    });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasks();
    } else {
        throw ToDoListException("Error: Task not found.");
    }
}

int ToDoList::getUncompletedTasks() const {
    int count = 0;
    for (const auto& task : tasks) {
        if (!task->isCompleted()) {
            count++;
        }
    }
    return count;
}

void ToDoList::modifyTask(const std::string& title, const std::string& newDescription) {
    ToDo* taskToModify = findTask(title);
    if (taskToModify) {
        taskToModify->modifyDescription(newDescription);
        saveTasks();
    } else {
        throw ToDoListException("Error: Task not found.");
    }
}

void ToDoList::modifyPriority(const std::string &title, int newPriority) {
    ToDo* taskToModify = findTask(title);
    if (taskToModify) {
        taskToModify->setPriority(newPriority);
        saveTasks();
    } else {
        throw ToDoListException("Error: Task not found.");
    }

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
    ToDo* taskToMark = findTask(title);
    if (taskToMark) {
        taskToMark->markAsCompleted();
        saveTasks();
    } else {
        throw ToDoListException("Error: Task not found.");
    }
}

std::string ToDoList::getFullPath(const std::string& filename) {
    std::__fs::filesystem::path cwd = std::__fs::filesystem::current_path();
    std::__fs::filesystem::path fullPath = cwd / filename;
    return fullPath.string();
}

ToDo* ToDoList::findTask(const std::string& title) {
    for (const auto& task : tasks) {
        if (task->getTitle() == title) {
            return task.get();
        }
    }
    return nullptr;
}

void ToDoList::saveTasks() {
    std::string fullPath = getFullPath(filename);
    std::ofstream outfile(fullPath);
    if (!outfile.is_open()) {
        throw ToDoListException("Error: Could not open file to save tasks.");
    }
    for (const auto& task : tasks) {
        outfile << task->getTitle() << ',' << task->getDescription() << ',' << task->getPriority() << ',' << (task->isCompleted() ? "1" : "0") << '\n';
    }
    if (!outfile.good()) {
        throw ToDoListException("Error: Could not write to file.");
    }
}

void ToDoList::loadTasks(const std::string& newFilename) {
    filename = newFilename;
    std::string fullPath = getFullPath(filename);
    std::ifstream infile(fullPath);
    if (!infile.is_open()) {
        return; //file doesn't exist, no tasks to load
    }
    std::string line;
    std::vector<std::unique_ptr<ToDo>> loadedTasks;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string title, description;
        int priority;
        std::string completed;
        std::getline(iss, title, ',');
        std::getline(iss, description, ',');
        iss >> priority;
        std::getline(iss, completed, ',');
        auto task = std::make_unique<ToDo>(title, description, priority);  //using make_unique
        if (completed == "1") {
            task->markAsCompleted();
        }
        loadedTasks.push_back(std::move(task));
    }
    if (infile.bad()) {
        throw ToDoListException("Error: Could not read from file.");
    }
    tasks = std::move(loadedTasks);
}