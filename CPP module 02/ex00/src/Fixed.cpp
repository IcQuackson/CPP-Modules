
#include "../includes/Fixed.hpp"

const int Fixed::_numFracBits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->number = fixed.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}
