
#include "ToDoList.h"
#include "ToDoListException.h"
#include <iostream>

int main() {
    ToDoList todoList;

    try {
        // Add tasks
        todoList.addTask("Buy milk", "", 1);
        todoList.addTask("Do laundry", "Wash, dry, and fold clothes", 2);
        todoList.addTask("Study for exam", "", 3);

        // Modify a task
        todoList.modifyTask("Do laundry", "Wash, dry, fold, and iron clothes");

        // Mark a task as completed
        todoList.markAsCompleted("Buy milk");

        // Remove a task
        todoList.removeTask("Do laundry");

        // Organize tasks by priority
        todoList.organizeTasks();
    } catch (const ToDoListException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Tasks after addition:" << std::endl;
    todoList.displayTasks();

    std::cout << "\nTasks after modification:" << std::endl;
    todoList.displayTasks();

    std::cout << "\nTasks after marking as completed:" << std::endl;
    todoList.displayTasks();

    std::cout << "\nUncompleted tasks:" << std::endl;
    todoList.displayTasks([](const ToDo& task) { return !task.isCompleted(); });

    std::cout << "\nTasks after removal:" << std::endl;
    todoList.displayTasks();

    std::cout << "\nTasks by priority:" << std::endl;
    todoList.displayTasksByPriority();

    std::cout << "\nOrganized tasks by priority:" << std::endl;
    todoList.displayTasks();

    return 0;
}
