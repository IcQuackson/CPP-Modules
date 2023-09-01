
#pragma once

#include <iostream>

class Fixed {

private:
	int number;
	static const int _numFracBits;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
