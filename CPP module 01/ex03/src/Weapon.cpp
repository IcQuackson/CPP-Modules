#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string name) : type(name) {}

const std::string& Weapon::getType(void) {
	return this->type;
}

void Weapon::setType(std::string new_type) {
	this->type = new_type;
}
