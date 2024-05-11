


#include "ToDoList.h"
#include "ToDo.h"

int main() {
    ToDoList todoList;

    todoList.addTask(ToDo("Buy milk"));
    todoList.addTask(ToDo("Do laundry", "Wash, dry, and fold clothes"));
    todoList.addTask(ToDo("Study for exam"));

    todoList.displayTasks();

    todoList.modifyTask("Do laundry", "Wash, dry, fold, and iron clothes");
    todoList.markAsCompleted("Buy milk");

    todoList.displayTasks();

    todoList.displayUncompletedTasks();


    todoList.displayTasks();

    todoList.removeTask("Do laundry");
    todoList.displayTasks();

    return 0;
}