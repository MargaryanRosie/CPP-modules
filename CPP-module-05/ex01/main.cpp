#include "Bureaucrat.hpp"

int main()
{
    Form form ("Form 1", 50, 10);
    
    std::cout << form << std::endl;


    std::cout << "-------- Test signing ---------" << std::endl;

    Bureaucrat brc("Alice", 50);
    brc.signForm(form);

    std::cout << form << std::endl;

    Bureaucrat bob("Bob", 80);

    bob.signForm(form);

    std::cout << form << std::endl;


    std::cout << "--------- Test Invalid Form ----------" << std::endl;

    try
    {
        Form invalidForm("Invalid Form", 0, 20);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}