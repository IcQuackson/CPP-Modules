#include "../includes/Animal.hpp"

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
    this->type = "";
}

Animal::Animal(const Animal &animal) {
    std::cout << "Animal copy constructor called" << std::endl;
    
}

Animal& Animal::operator= (const Animal &animal) {
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &animal) {
        this->type = animal.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Default Animal sound" << std::endl;
}