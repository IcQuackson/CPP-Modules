
#include "../includes/Fixed.hpp"

const int Fixed::_numFracBits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _numFracBits);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << _numFracBits)));
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
		setRawBits(fixed.getRawBits());
	}
	return *this;
}

int	Fixed::getRawBits(void) const {
	return this->number;
}

void Fixed::setRawBits(int const raw) {
	this->number = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float> (this->getRawBits()) / (1 << _numFracBits);
}

int Fixed::toInt(void) const {
	return this->number >> _numFracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
