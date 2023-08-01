
#include "../includes/Zombie.hpp"

Zombie* Zombie::newZombie(std::string name) {
	Zombie *zombie = new Zombie(name);
	zombie->announce();
	return zombie;
}