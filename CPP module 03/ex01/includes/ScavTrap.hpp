#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &clapTrap);
	ScavTrap& operator= (const ScavTrap &clapTrap);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};
