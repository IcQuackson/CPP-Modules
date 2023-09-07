
#pragma once

#include <iostream>

class AAnimal {

protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &animal);
    AAnimal &operator= (const AAnimal &animal);
    virtual ~AAnimal();

	std::string getType() const;
    virtual void makeSound() const = 0;
};
