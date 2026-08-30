#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void testAnimalArray()
{
    const int size = 6;
    Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < size; ++i)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i)
        delete animals[i];
}

static void testDogDeepCopy()
{
    std::cout << "\n---- Deep Copy Test ----\n" << std::endl;

    Dog* original = new Dog();
    Dog* copy = new Dog(*original);
    delete original;
    std::cout << "Copy still alive after original is deleted: ";
    copy->makeSound();
    delete copy;
}

static void testWrongPolymorphism()
{
    std::cout << "\n----- Wrong Polymorphism -----\n" << std::endl;
    WrongCat wrongCat;
    const WrongAnimal* base = &wrongCat;
    std::cout << "Through WrongAnimal*: ";
    base->makeSound();
    std::cout << "Direct WrongCat call: ";
    wrongCat.makeSound();
}

int main()
{
    testAnimalArray();
    testDogDeepCopy();
    testWrongPolymorphism();
    return 0;
}

