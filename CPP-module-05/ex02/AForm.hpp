#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool status;
    const int gradeToSign;
    const int gradeToExecute;

    virtual void action() const = 0;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& brc);

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

    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& s, const AForm& AForm);

#endif