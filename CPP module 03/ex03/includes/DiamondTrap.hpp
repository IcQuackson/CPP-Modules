
#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

private:
	std::string name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
};