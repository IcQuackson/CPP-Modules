#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "AAnimal default constructor called" << std::endl;
    this->type = "default";
}

AAnimal::AAnimal(const AAnimal &animal) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = animal;
}

AAnimal& AAnimal::operator= (const AAnimal &animal) {
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &animal) {
        this->type = animal.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::makeSound() const {
    std::cout << "Default AAnimal sound" << std::endl;
}