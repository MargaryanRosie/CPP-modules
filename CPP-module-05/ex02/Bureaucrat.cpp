#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Initial name"), grade(1)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
        :name(other.name), grade(other.grade)
{
}

//as name is const, the object should keep its own name
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

Bureaucrat::Bureaucrat(std::string n, int g)
    : name(n), grade(g)
{
    if (g < 1)
        throw GradeTooHighException();
    else if (g > 150)
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "The grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "The grade is too low !";
}

void Bureaucrat::increment()
{
    if((grade - 1) >= 1 && ((grade - 1) <= 150))
        grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
    if((grade + 1) >= 1 && ((grade + 1) <= 150))
        grade++;
    else
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}


void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}