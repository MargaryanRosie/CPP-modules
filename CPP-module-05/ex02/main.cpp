#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat brc("Bob", 10);
    ShrubberyCreationForm a ("hello");
    ShrubberyCreationForm b ("hi");

    brc.signForm(a);

    a.execute(brc);
}