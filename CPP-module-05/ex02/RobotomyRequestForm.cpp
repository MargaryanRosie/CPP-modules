#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& targetName)
    : AForm("RobotomyRequestForm", 72, 45), target(targetName)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
    std::cout << "* BZZZZZZ DRRRRRRILL *" << std::endl;

    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << target << " failed" << std::endl;
}