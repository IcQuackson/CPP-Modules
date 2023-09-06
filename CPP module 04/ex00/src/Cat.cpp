#include "../includes/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "";
}

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = "Cat";
}

Cat& Cat::operator= (const Cat &cat) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &cat) {
        this->type = cat.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "MEOWWWWWWW" << std::endl;
}