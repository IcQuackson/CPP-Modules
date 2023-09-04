
#pragma once

#include <iostream>
#include <string>

class ClapTrap {

private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap& operator= (const ClapTrap &clapTrap);
	~ClapTrap();

	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

	void setHitPoints(int hitPoints);
	void setEnergyPoints(int energyPoints);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};