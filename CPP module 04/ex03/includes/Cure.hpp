#pragma once

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
	
public:
	Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);
	virtual ~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};
