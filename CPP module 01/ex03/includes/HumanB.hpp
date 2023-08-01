
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	std::string name;
	Weapon *weapon;

public:
	HumanB( std::string name );

	void attack( void );
	Weapon* getWeapon( void );
	void setWeapon( Weapon& weapon );
};

#endif
