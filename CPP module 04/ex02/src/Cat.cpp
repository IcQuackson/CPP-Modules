#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal() {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : AAnimal() {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat& Cat::operator= (const Cat &cat) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &cat) {
        this->type = cat.type;
		this->brain = new Brain();
		*this->brain = *cat.brain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Brain *Cat::getBrain() const {
	return this->brain;
}

void Cat::makeSound() const {
    std::cout << "MEOWWWWWWW" << std::endl;
}