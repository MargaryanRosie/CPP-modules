#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));        //tells rand() where to start

    std::cout << "--------- Test 1 ----------" << std::endl;
    try
    {
        Bureaucrat A("A", 1);
        ShrubberyCreationForm form("first");
        A.executeForm(form);
    }
    catch (std::exception& e)
    {
        //std::cout << "Enters catch of the main" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------- Test 2 ----------" << std::endl;
    try
    {
        Bureaucrat clerk("clerk", 140);
        ShrubberyCreationForm form("office");
        clerk.signForm(form);
        clerk.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    } 

    std::cout << std::endl << "-------- Test 3 -------" << std::endl;
    try
    {
        Bureaucrat B("B", 137);
        ShrubberyCreationForm form("home");
        B.signForm(form);
        B.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "---------- Test4 ----------" << std::endl;
    try
    {
        Bureaucrat boss("boss", 1);
        RobotomyRequestForm form("Hello");
        boss.signForm(form);
        for (int i = 0; i < 10; i++)
            boss.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << std::endl << "-------- Test 5 ---------" << std::endl;
    try
    {
        Bureaucrat exact("exact", 45);
        Bureaucrat tooLow("tooLow", 46);
        RobotomyRequestForm form("Marvin");
        exact.signForm(form);
        exact.executeForm(form);
        tooLow.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}