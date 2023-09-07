#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator= (const Brain &brain) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = brain.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
