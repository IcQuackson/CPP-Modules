
#include "../includes/Zombie.hpp"

int main() {
	Zombie *horde = zombieHorde(10, "TONI");
	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
