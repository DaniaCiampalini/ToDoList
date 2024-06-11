#ifndef TODOLIST_TODOLISTEXCEPTION_H
#define TODOLIST_TODOLISTEXCEPTION_H

#include <stdexcept>
#include <string>

class ToDoListException : public std::runtime_error {
public:
    explicit ToDoListException(const std::string& what) : std::runtime_error(what) {}
};

#endif // TODOLIST_TODOLISTEXCEPTION_H