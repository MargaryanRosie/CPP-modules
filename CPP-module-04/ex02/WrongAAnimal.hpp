#ifndef WRONGA_AAnimal_HPP
# define WRONGA_AAnimal_HPP

#include <iostream>
#include <string>

class WrongAAnimal
{
protected:
    std::string type;
public:
    WrongAAnimal();
    WrongAAnimal(const WrongAAnimal& other);
    WrongAAnimal& operator=(const WrongAAnimal& other);
    ~WrongAAnimal();

    void makeSound() const;
    std::string getType() const;
};

#endif