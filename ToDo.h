
#ifndef TODO_H
#define TODO_H

#include <string>

class ToDo {
public:
    ToDo(); //default constructor
    explicit ToDo(std::string title, std::string description = ""); //non-default constructor

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    void setTitle(std::string newTitle);
    void modifyDescription(const std::string& newDescription);
    void markAsCompleted();
    bool isCompleted() const;
    void setCompleted(bool isCompleted);
    int getPriority() const;
    void setPriority(int newPriority);


private:
    std::string title;
    std::string description;
    bool completed;
    int priority{};


};

#endif