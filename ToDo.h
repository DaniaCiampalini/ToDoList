
#ifndef TODO_H
#define TODO_H

#include <string>
#include <iostream>

class ToDo {
public:
    explicit ToDo(std::string title, std::string description = "", int priority = 1);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    int getPriority() const;

    void setTitle(std::string newTitle);
    void modifyDescription(const std::string& newDescription);
    void setPriority(int newPriority);

    void markAsCompleted();
    bool isCompleted() const;

    void display() const;

private:
    std::string title;
    std::string description;
    int priority;
    bool completed;
};

#endif // TODO_H
