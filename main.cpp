
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

        std::cout << "Tasks after addition:" << std::endl;
        todoList.displayTasks();

        // Modify a task
        todoList.modifyTask("Do laundry", "Wash, dry, fold, and iron clothes");

        std::cout << "\nTasks after modification:" << std::endl;
        todoList.displayTasks();

        // Mark a task as completed
        todoList.markAsCompleted("Buy milk");

        std::cout << "\nTasks after marking as completed:" << std::endl;
        todoList.displayTasks();

        std::cout << "\nUncompleted tasks:" << std::endl;
        todoList.displayTasks([](const ToDo& task) { return !task.isCompleted(); });

        // Remove a task
        todoList.removeTask("Do laundry");

        std::cout << "\nTasks after removal:" << std::endl;
        todoList.displayTasks();

        // Display tasks by priority
        todoList.displayTasksByPriority();

        // Organize tasks by priority
        todoList.organizeTasks();

        std::cout << "\nOrganized tasks by priority:" << std::endl;
        todoList.displayTasks();
    } catch (const ToDoListException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
