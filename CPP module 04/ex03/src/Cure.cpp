
#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator=(Cure const &other) {
	//std::cout << "Cure assignation operator called" << std::endl;
    this->type = other.type;
	return *this;
}

Cure::~Cure() {
	//std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;
}
