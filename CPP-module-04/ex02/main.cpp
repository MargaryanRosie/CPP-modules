#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"

static void testAAnimalArray()
{
    const int size = 6;
    AAnimal* AAnimals[size];

    for (int i = 0; i < size / 2; ++i)
        AAnimals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        AAnimals[i] = new Cat();

    for (int i = 0; i < size; ++i)
    {
        AAnimals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i)
        delete AAnimals[i];
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
    const WrongAAnimal* base = &wrongCat;
    std::cout << "Through WrongAAnimal*: ";
    base->makeSound();
    std::cout << "Direct WrongCat call: ";
    wrongCat.makeSound();
}

int main()
{
    testAAnimalArray();
    testDogDeepCopy();
    testWrongPolymorphism();
    return 0;
}
