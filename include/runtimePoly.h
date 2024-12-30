#ifndef RUNTIMEPOLY_H
#define RUNTIMEPOLY_H

#include <iostream>

// Base class
class Animal {
public:
    // Virtual function (enables runtime polymorphism)
    virtual void sound() const;

    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Animal();
};

// Derived class 1
class Dog : public Animal {
public:
    void sound() const override;
};

// Derived class 2
class Cat : public Animal {
public:
    void sound() const override;
};

#endif // RUNTIMEPOLY_H
