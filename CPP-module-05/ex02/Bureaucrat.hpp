#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(std::string n, int g);
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();

    void signForm(AForm& AForm);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif