
#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	setHitPoints(100);
    setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap created" << std::endl;
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
    setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap created: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &scavTrap) {
	ClapTrap::operator=(scavTrap);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destroyed: ";
	std::cout << "Name: " << getName() << ", ";
	std::cout << "Hit Points: " << getHitPoints() << ", ";
	std::cout << "Energy Points: " << getEnergyPoints() << ", ";
	std::cout << "Attack Damage: " << getAttackDamage() << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0) {
		std::cout << "ScavTrap " << this->getName() << " can't attack!" << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << getName() << " attacks " << target << ", ";
	std::cout << "causing " << getAttackDamage() << " points of damage!" << std::endl;

	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " has entered in Gate keeper mode." << std::endl;
}
