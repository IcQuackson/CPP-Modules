
#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void) {
	std::cout << this->name << std::endl;
	return ;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::announce(void) const {
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
