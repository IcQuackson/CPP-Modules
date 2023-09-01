
#include "../includes/Fixed.hpp"

const int Fixed::NUM_FRAC_BITS = 8;

Fixed::Fixed(void) {
	this->number = 0;
}

Fixed::Fixed(const int value) {
	setRawBits(value << NUM_FRAC_BITS);
}

Fixed::Fixed(const float value) {
	setRawBits(roundf(value * (1 << NUM_FRAC_BITS)));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed &fixed) {
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
	return static_cast<float> (this->getRawBits()) / (1 << NUM_FRAC_BITS);
}

int Fixed::toInt(void) const {
	return this->number >> NUM_FRAC_BITS;
}

std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator== (const Fixed& fixed) const {
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!= (const Fixed& fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

bool Fixed::operator< (const Fixed& fixed) const {
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>	(const Fixed& fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<=	(const Fixed& fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator>=	(const Fixed& fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}

Fixed Fixed::operator+	(Fixed const &fixed) const {
	Fixed result;

	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-	(const Fixed& fixed) const {
	Fixed result;

	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*	(const Fixed& fixed) const {
	Fixed result;

	result.setRawBits(this->toFloat() * fixed.toFloat() * (1 << NUM_FRAC_BITS));
	return result;
}

Fixed Fixed::operator/	(const Fixed& fixed) const {
	Fixed result;

	result.setRawBits(this->toFloat() / fixed.toFloat() * (1 << NUM_FRAC_BITS));
	return result;
}

Fixed& Fixed::operator++() {
	this->number++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;

	this->number++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->number--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;

	this->number--;
	return temp;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 < fixed2) {
		return fixed1;
	}
	else {
		return fixed2;
	}
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 < fixed2) {
		return fixed1;
	}
	else {
		return fixed2;
	}
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 > fixed2) {
		return fixed1;
	}
	else {
		return fixed2;
	}
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 > fixed2) {
		return fixed1;
	}
	else {
		return fixed2;
	}
}
