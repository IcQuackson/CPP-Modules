#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog& Dog::operator= (const Dog &dog) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &dog) {
        this->type = dog.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "OOOF OOOF" << std::endl;
}
