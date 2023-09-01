
#include "../includes/Fixed.hpp"

const int Fixed::NUM_FRAC_BITS = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << NUM_FRAC_BITS);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << NUM_FRAC_BITS)));
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
	return static_cast<float> (getRawBits()) / (1 << NUM_FRAC_BITS);
}

int Fixed::toInt(void) const {
	return this->number >> NUM_FRAC_BITS;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
