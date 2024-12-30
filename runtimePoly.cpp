#include "runtimePoly.h"

// Base class implementation
void Animal::sound() const {
    std::cout << "Animal makes a sound" << std::endl;
}

Animal::~Animal() {}

// Derived class Dog implementation
void Dog::sound() const {
    std::cout << "Dog barks" << std::endl;
}

// Derived class Cat implementation
void Cat::sound() const {
    std::cout << "Cat meows" << std::endl;
}
