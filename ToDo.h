#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H

#include <string>

class ToDo {
public:
    explicit ToDo(std::string title, std::string description = "", int priority = 1);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    int getPriority() const;

    void setTitle(const std::string& newTitle);
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

#endif //TODOLIST_TODO_H