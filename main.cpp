
#include "ToDoList.h"

int main() {
    ToDoList todoList;

    todoList.addTask("Buy milk");
    todoList.addTask("Do laundry", "Wash, dry, and fold clothes");
    todoList.addTask("Study for exam");

    todoList.displayTasks();

    todoList.modifyTask("Do laundry", "Wash, dry, fold, and iron clothes");
    todoList.markAsCompleted("Buy milk");

    todoList.displayTasks();

    todoList.displayUncompletedTasks();

    todoList.removeTask("Do laundry");
    todoList.displayTasks();

    return 0;
}