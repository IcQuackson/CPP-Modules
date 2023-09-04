
#include "../includes/ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1("C1");
	clapTrap1.attack("enemy"); // hit points: 10, energy points: 9
	clapTrap1.takeDamage(5); // hit points: 5

	std::cout << "hit points: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "energy points: " << clapTrap1.getEnergyPoints() << std::endl;

	clapTrap1.beRepaired(5); // hit points: 10

	std::cout << "hit points: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "energy points: " << clapTrap1.getEnergyPoints() << std::endl;

	clapTrap1.takeDamage(15); // Dies
	std::cout << "hit points: " << clapTrap1.getHitPoints() << std::endl;
	clapTrap1.takeDamage(15); // Can't be damaged
	clapTrap1.attack("enemy"); // Can't attack
	clapTrap1.beRepaired(15); // Can't be repaired

	std::cout << std::endl;
	ClapTrap clapTrap2("C2");
	clapTrap2.beRepaired(1); // hit points: 11, energy points: 9
	std::cout << "energy points: " << clapTrap2.getEnergyPoints() << std::endl;
	clapTrap2.beRepaired(1); // hit points: 12, energy points: 8
	clapTrap2.beRepaired(1); // hit points: 13, energy points: 7
	clapTrap2.beRepaired(1); // hit points: 14, energy points: 6
	clapTrap2.beRepaired(1); // hit points: 15, energy points: 5
	clapTrap2.beRepaired(1); // hit points: 16, energy points: 4
	clapTrap2.beRepaired(1); // hit points: 17, energy points: 3
	clapTrap2.beRepaired(1); // hit points: 18, energy points: 2
	clapTrap2.beRepaired(1); // hit points: 19, energy points: 1
	clapTrap2.beRepaired(1); // hit points: 20, energy points: 0
	std::cout << "energy points: " << clapTrap2.getEnergyPoints() << std::endl;
	clapTrap2.beRepaired(1); // Can't repair

	clapTrap2.takeDamage(20); // Dies

	
	return 0;
}