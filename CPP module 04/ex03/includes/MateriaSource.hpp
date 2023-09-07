#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria *materia[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	virtual ~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria* createMateria(std::string const & type);
};
