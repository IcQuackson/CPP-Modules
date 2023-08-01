#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"
#include <iostream>


HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

Weapon& HumanA::getWeapon() {
	return this->weapon;
}

void HumanA::attack(void) {
	std::cout << name << " attacks with their " << getWeapon().getType() << std::endl;
}
