
#include <iostream>
#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie( std::string name );
	Zombie( void );
	~Zombie( void );

	void announce( void ) const;
	Zombie* zombieHorde( int N, std::string name );
};
