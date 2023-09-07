
#pragma once

#include <iostream>

class Animal {

protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &animal);
    Animal &operator= (const Animal &animal);
    virtual ~Animal();

	std::string getType() const;
    virtual void makeSound() const;
};
