
#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	//std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	//std::cout << "MateriaSource assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
		this->materia[i] = other.materia[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->materia[i])
			delete this->materia[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++)
	{
		if (!this->materia[i])
		{
			//std::cout << "Materia learned: " << m->getType() << std::endl;
			this->materia[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && this->materia[i]->getType() == type) {
			//std::cout << "Materia created: " << this->materia[i]->getType() << std::endl;
			return this->materia[i]->clone();
		}
	}
	return NULL;
}
