
#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
	Brain *brain;

public:
    Dog();
    Dog(const Dog &dog);
    Dog &operator= (const Dog &dog);
    ~Dog();
    
    void makeSound() const;
	Brain *getBrain() const;
};