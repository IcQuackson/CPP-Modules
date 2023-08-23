
#include "../includes/Zombie.hpp"

void randomChump( std::string name ) {
	Zombie zombie = Zombie(name);
	zombie.announce();
}
