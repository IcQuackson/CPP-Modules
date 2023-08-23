
#include "../includes/Zombie.hpp"

int main() {
	randomChump("STACK");
	Zombie *zombie = newZombie("HEAP");
	zombie->announce();
	delete zombie;
}
