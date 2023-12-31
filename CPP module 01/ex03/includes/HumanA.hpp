
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {

private:
	std::string name;
	Weapon& weapon;

public:
	HumanA( std::string name, Weapon& weapon );

	Weapon& getWeapon( void );
	void attack( void );
};

#endif