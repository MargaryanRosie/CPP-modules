#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("Ann", 32);
    Bureaucrat b2("Sam", 46);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "------------ Increment and decrement test ------------" << std::endl;

    b1.increment();
    b2.increment();

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    b1.decrement();
    b2.decrement();

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "------------ Exceptions test ------------" << std::endl;

    try
    {
        Bureaucrat b3("Lima", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b4("Ken", 170);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("John", 1);
        b5.increment();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b6("Kate", 150);
        b6.decrement();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }   
}