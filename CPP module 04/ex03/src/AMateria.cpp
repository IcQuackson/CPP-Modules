#include "../includes/AMateria.hpp"

AMateria::AMateria() : type("default") {
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) {
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other) {
	(void) other;
	return *this;
}

AMateria::~AMateria() {
	//std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void) target;
}
