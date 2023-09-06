
#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : protected Animal {

public:
    Cat();
    Cat(const Cat &cat);
    Cat &operator= (const Cat &cat);
    ~Cat();

    void makeSound() const;
};