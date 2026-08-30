#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete dog;
    delete cat;
    delete meta;

    std::cout << "\n---------- Wrong -----------\n" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongCat* realWrongCat = new WrongCat();
    const WrongAnimal* wrongCatAsBase = realWrongCat;

    std::cout << "wrong cat type: " << wrongCatAsBase->getType() << std::endl;
    wrongAnimal->makeSound();
    wrongCatAsBase->makeSound();
    std::cout << "Direct WrongCat call: ";
    realWrongCat->makeSound();

    delete wrongAnimal;
    delete realWrongCat;

    std::cout << "\n----------- Copy Constructor -------------\n" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    std::cout << "dog copies: " << dog1.getType() << ", "
        << dog2.getType() << ", " << dog3.getType() << std::endl;
    std::cout << "cat copies: " << cat1.getType() << ", "
        << cat2.getType() << ", " << cat3.getType() << std::endl;

    return 0;
}
