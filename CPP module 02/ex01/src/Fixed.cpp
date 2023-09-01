
#include "../includes/Fixed.hpp"

const int Fixed::NUM_FRAC_BITS = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->number = value << NUM_FRAC_BITS;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(value * (1 << NUM_FRAC_BITS));
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
		this->number = fixed.number;
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

float Fixed::toFloat(void) const {
	return static_cast<float> (this->number) / (1 << NUM_FRAC_BITS);
}

int Fixed::toInt(void) const {
	return this->number >> NUM_FRAC_BITS;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
