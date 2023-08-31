
#pragma once

#include <iostream>

class Fixed {

private:
	int integerPart;
	static const int NUM_FRAC_BITS;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
