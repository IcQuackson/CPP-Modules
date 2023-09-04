#include "../includes/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap created: ";
	std::cout << "Name: " << this->name << ", ";
	std::cout << "Hit Points: " << this->hitPoints << ", ";
	std::cout << "Energy Points: " << this->energyPoints << ", ";
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap created: ";
	std::cout << "Name: " << this->name << ", ";
	std::cout << "Hit Points: " << this->hitPoints << ", ";
	std::cout << "Energy Points: " << this->energyPoints << ", ";
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &clapTrap) {
	if (this != &clapTrap) {
		this->name = clapTrap.name;
		this->hitPoints = clapTrap.hitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->attackDamage = clapTrap.attackDamage;
	}
	std::cout << "Assignment called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destroyed: ";
	std::cout << "Name: " << this->name << ", ";
	std::cout << "Hit Points: " << this->hitPoints << ", ";
	std::cout << "Energy Points: " << this->energyPoints << ", ";
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}

std::string ClapTrap::getName() const {
	return this->name;
}

int ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

void ClapTrap::setHitPoints(int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::attack(const std::string& target) {
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " can't attack!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->getName() << " attacks " << target <<\
	", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " is already dead!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->getName() << " takes " << amount <<\
	" points of damage!" << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
	
	if (this->getHitPoints() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " dies!" << std::endl;
		this->setHitPoints(0);
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0) {
		std::cout << "ClapTrap " << this->getName() << " can't be repaired!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->getName() << " is repaired for " << amount <<\
	" points of health!" << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
