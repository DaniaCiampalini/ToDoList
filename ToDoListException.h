#ifndef TODOLIST_TODOLISTEXCEPTION_H
#define TODOLIST_TODOLISTEXCEPTION_H

#include <exception>
#include <string>

class ToDoListException : public std::exception {
public:
    explicit ToDoListException(std::string message) : message(std::move(message)) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif //TODOLIST_TODOLISTEXCEPTION_H