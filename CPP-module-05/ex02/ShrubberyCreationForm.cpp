#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& targetName)
    : AForm("ShrubberyCreationForm", 145, 137), target(targetName)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
    std::string fileName = target + "_shrubbery";
    std::ofstream out(fileName.c_str());

    if(!out)
        throw FileOpenException();

    out << "    *" << std::endl;
    out << "   ***" << std::endl;
    out << "  *****" << std::endl;
    out << " *******" << std::endl;
    out << "    |" << std::endl;
    out << "    |" << std::endl;
    out << std::endl;


    out << "      ^" << std::endl;
    out << "     ^^^" << std::endl;
    out << "    ^^^^^" << std::endl;
    out << "   ^^^^^^^" << std::endl;
    out << "  ^^^^^^^^^" << std::endl;
    out << " ^^^^^^^^^^^" << std::endl;
    out << "      |||" << std::endl;
    out << "      |||" << std::endl;
    out << std::endl;

    out << "   @@@" << std::endl;
    out << "  @@@@@" << std::endl;
    out << " @@@@@@@" << std::endl;
    out << "  @@@@@" << std::endl;
    out << "    |" << std::endl;
    out << "    |" << std::endl;
}