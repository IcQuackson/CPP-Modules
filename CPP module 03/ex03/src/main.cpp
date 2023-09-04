
#include "../includes/DiamondTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

int main() {
	DiamondTrap diamondTrap("DiamondTrap");
	diamondTrap.attack("target");
	std::cout << "Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.takeDamage(10);
	std::cout << "Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.beRepaired(10);
	std::cout << "Energy Points: " << diamondTrap.getEnergyPoints() << std::endl;
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();
	diamondTrap.whoAmI();

	return 0;
}