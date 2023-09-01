
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

	// Comparison operator overload
	bool operator==	(const Fixed& fixed) const;
	bool operator!=	(const Fixed& fixed) const;
	bool operator<	(const Fixed& fixed) const;
	bool operator>	(const Fixed& fixed) const;
	bool operator<=	(const Fixed& fixed) const;
	bool operator>=	(const Fixed& fixed) const;

	// Arithmetic operator overload
	Fixed operator+	(const Fixed& fixed) const;
	Fixed operator-	(const Fixed& fixed) const;
	Fixed operator*	(const Fixed& fixed) const;
	Fixed operator/	(const Fixed& fixed) const;

	// Increment/Decrement operator overload
	Fixed& operator++(); 
    Fixed operator++(int); 
    Fixed& operator--(); 
    Fixed operator--(int); 

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed& 		min(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
