
#include "../includes/FragTrap.hpp"

int main() {
	// test scavtrap
	FragTrap fragTrap("FragTrap");
	fragTrap.attack("target");
	std::cout << "Energy Points: " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.takeDamage(10);
	std::cout << "Energy Points: " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.beRepaired(10);
	std::cout << "Energy Points: " << fragTrap.getEnergyPoints() << std::endl;
	fragTrap.highFivesGuys();
	

	return 0;
}