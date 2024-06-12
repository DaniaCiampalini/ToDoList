
#include "ToDoList.h"
#include "ToDoListException.h"
#include <iostream>

int main() {
    ToDoList todoList;
    bool stop = false;
    int option;  //to store the user's option

    std::cout << std::endl;
    std::cout << "**************** Welcome to my Todo List! ******************" << std::endl;
    std::cout << "\nList of options: " << std::endl;
    std::cout << "1) Add a new Todo " << std::endl;
    std::cout << "2) Remove a Todo " << std::endl;
    std::cout << "3) Modify a Todo " << std::endl;
    std::cout << "4) Mark a Todo as completed " << std::endl;
    std::cout << "5) Modify priority of a Todo " << std::endl;
    std::cout << "6) Display tasks by priority" << std::endl;
    std::cout << "7) Display uncompleted todos" << std::endl;
    std::cout << "8) Display all todos " << std::endl;
    std::cout << "9) Save todos in a file" << std::endl;
    std::cout << "10) Upload todos from a file" << std::endl;
    std::cout << "11) Exit" << std::endl;
    std::cout << "12) Display options" << std::endl;

    //loop until the user chooses to exit
    do {
        std::cout << "\n************************************************************" << std::endl;
        std::cout << "\nChoose Your option(press 0 to exit and 12 to see the list again): ";
        std::cin >> option;

        //variables to store user input
        std::string title, description, newDescription, fileName;
        int priority, newPriority;

        try {
            switch (option) {
                case 0:
                    stop = true;
                    std::cout << "\n************************************************************" << std::endl;
                    std::cout << "\nThank you for using my application...\nGoodbye!" << std::endl;
                    std::cout << "\n************************************************************" << std::endl;
                    break;
                case 1:
                    std::cout << "Please enter the title of the todo: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Please enter the description of the todo: ";
                    std::getline(std::cin, description);
                    std::cout << "Please enter the priority of the todo: ";
                    std::cin >> priority;
                    todoList.addTask(title, description, priority);
                    break;
                case 2:
                    std::cout << "Please enter the title of the todo to remove: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    todoList.removeTask(title);
                    break;
                case 3:
                    std::cout << "Please enter the title of the todo to modify: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Please enter the new description: ";
                    std::getline(std::cin, newDescription);
                    todoList.modifyTask(title, newDescription);
                    break;
                case 4:
                    std::cout << "Please enter the title of the todo to set as completed: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    todoList.markAsCompleted(title);
                    break;
                case 5:
                    std::cout << "Please enter the title of the todo to modify priority: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Please enter the new priority: ";
                    std::cin >> newPriority;
                    todoList.modifyPriority(title, newPriority);
                    break;
                case 6:
                    todoList.displayTasksByPriority();
                    break;
                case 7:
                    todoList.displayTasks([](const ToDo& task) { return!task.isCompleted(); });
                    break;
                case 8:
                    todoList.displayTasks();
                    break;
                case 9:
                    std::cout << "Please enter the filename to save: ";
                    std::cin.ignore();
                    std::getline(std::cin, fileName);
                    try {
                        todoList.saveTasks();
                    } catch (const ToDoListException& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    break;
                case 10:
                    std::cout << "Please enter the filename to upload: ";
                    std::cin.ignore();
                    std::getline(std::cin, fileName);
                    try {
                        todoList.loadTasks(fileName);
                    } catch (const ToDoListException& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    break;
                case 11:
                    stop = true;
                    break;
                case 12:
                    std::cout << "\nList of options: " << std::endl;
                    std::cout << "1) Add a new Todo" << std::endl;
                    std::cout << "2) Remove a Todo" << std::endl;
                    std::cout << "3) Modify a Todo" << std::endl;
                    std::cout << "4) Mark a Todo as completed" << std::endl;
                    std::cout << "5) Modify priority of a Todo" << std::endl;
                    std::cout << "6) Display tasks by priority" << std::endl;
                    std::cout << "7) Display uncompleted todos" << std::endl;
                    std::cout << "8) Display all todos" << std::endl;
                    std::cout << "9) Save todos in a file" << std::endl;
                    std::cout << "10) Upload todos from a file" << std::endl;
                    std::cout << "11) Exit" << std::endl;
                    break;
                default:
                    std::cout << "Please enter a valid option!" << std::endl;
            }
        } catch (const ToDoListException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (!stop);

    return 0;
}
