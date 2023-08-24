#include <iostream>
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"


HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

Weapon* HumanB::getWeapon() {
	return weapon;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	if (this->weapon != NULL)
		std::cout << name << " attacks with their " << getWeapon()->getType() << std::endl;
}
