#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animals[100];

    std::cout << "========== Test Construction ==========\n\n" << std::endl;

    int i = 0;
    for (; i < 50; i++) {
        animals[i] = new Cat();
    }
    for (; i < 100; i++) {
        animals[i] = new Dog();
    }

    std::cout << "========== Testing Brain Access ==========\n\n" << std::endl;
    for (size_t i = 0; i < 100; i++) {
        std::cout << "Animal Type: " << animals[i]->getType() << " Said: ";
        animals[i]->makeSound();
    }

    std::cout << "========== Deep Copy Test ==========\n\n" << std::endl;
    Cat originalCat;    
    Cat copyCat(originalCat);
    

    std::cout << "\n========== Testing Copy Assignment ==========\n\n" << std::endl;
    Cat assignCat;
    assignCat = originalCat;


    std::cout << "========== Test Destruction ==========\n\n" << std::endl;
    for (i = 0; i < 100; i++) {
        std::cout << "Deleting Animal " << i << std::endl;
        delete animals[i];
    }

    return 0;
}
