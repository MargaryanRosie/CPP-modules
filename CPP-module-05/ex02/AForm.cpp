#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name ("Default"), status (false), gradeToSign(150), gradeToExecute(150)
{

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), status(false),
    gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        status = other.status;
    }
    return (*this);
}

AForm::AForm(const AForm& other)
    : name(other.name),
      status(other.status),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{

}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getStatus() const
{
    return status;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& brc)
{
    if (brc.getGrade() > gradeToSign)
        throw GradeTooLowException();

    status = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "The form is not signed!";
}

std::ostream& operator<<(std::ostream& s, const AForm& AForm)
{
    s << "AForm name: " << AForm.getName() << std::endl;
    s << "Signed: " << std::boolalpha << AForm.getStatus() << std::endl;
    s << "Grade required to sign: " << AForm.getGradeToSign() << std::endl;
    s << "Grade required to execute: " << AForm.getGradeToExecute();

    return s;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (status != true)
        throw FormNotSignedException();

    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();

    action();
}