#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	
protected:
	std::string type;

public:
	AMateria();
	AMateria(AMateria const &other);
	AMateria(std::string const &type);
	AMateria &operator=(AMateria const &other);
	virtual ~AMateria();

	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
