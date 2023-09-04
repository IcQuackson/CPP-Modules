
#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap created: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destroyed: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " is asking for high fives!" << std::endl;
}
