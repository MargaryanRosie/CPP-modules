#include "WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
    type = "WrongAAnimal";
    std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& other)
{
    std::cout << "WrongAAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAAnimal& WrongAAnimal::operator=(const WrongAAnimal& other)
{
    std::cout << "WrongAAnimal copy assignment operator called" << std::endl;

    type = other.type;

    return *this;
}

WrongAAnimal::~WrongAAnimal()
{
    std::cout << "WrongAAnimal destructor called" << std::endl;
}

void WrongAAnimal::makeSound() const
{
    std::cout << "Some WrongAAnimal sound" << std::endl;
}

std::string WrongAAnimal::getType() const
{
    return type;
}