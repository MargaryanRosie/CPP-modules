#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat brc("Bob", 10);
    ShrubberyCreationForm a ("hello");
    ShrubberyCreationForm b ("hi");

    brc.signForm(a);

    b = a;

    std::cout << b << std::endl;
}