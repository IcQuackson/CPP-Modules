
#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : protected Animal {

public:
    Dog();
    Dog(const Dog &dog);
    Dog &operator= (const Dog &dog);
    ~Dog();
    
    void makeSound() const;
};