#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name ("Default"), status (false), gradeToSign(150), gradeToExecute(150)
{

}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), status(false),
    gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        status = other.status;
    }
    return (*this);
}

Form::Form(const Form& other)
    : name(other.name),
      status(other.status),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{

}

Form::~Form()
{

}

std::string Form::getName() const
{
    return name;
}

bool Form::getStatus() const
{
    return status;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > gradeToSign)
        throw GradeTooLowException();

    status = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}