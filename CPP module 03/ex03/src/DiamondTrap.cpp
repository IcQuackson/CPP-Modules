
#include "../includes/DiamondTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	setName(name);
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap created: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destroyed: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << getName() << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}
