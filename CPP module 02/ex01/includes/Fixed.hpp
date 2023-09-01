
#pragma once

#include <iostream>
#include <cmath>

class Fixed {

private:
	int number;
	static const int _numFracBits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
