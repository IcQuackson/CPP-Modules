
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
	// test scavtrap
	ScavTrap scavTrap("ScavTrap");
	scavTrap.attack("target");
	std::cout << "Energy Points: " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.takeDamage(10);
	std::cout << "Energy Points: " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.beRepaired(10);
	std::cout << "Energy Points: " << scavTrap.getEnergyPoints() << std::endl;
	scavTrap.guardGate();
	

	return 0;
}