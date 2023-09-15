
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base *generate(void) {
	int randomNumber;
	std::srand(time(NULL));

	randomNumber = 1 + (rand() % 3);

    std::cout << "Random number between 1 and 3: " << randomNumber << std::endl;

	switch (randomNumber)
	{
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();		
		default:
			return NULL;
	}
}

void identify(Base* p) {
	A* derivedA = dynamic_cast<A*>(p);
	B* derivedB = dynamic_cast<B*>(p);
	C* derivedC = dynamic_cast<C*>(p);

	if (derivedA) {
		std::cout << "A" << std::endl;
	} else if (derivedB) {
		std::cout << "B" << std::endl;
	} else if (derivedC) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
		try {
			(void) dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::exception &e) {
			try {
				(void) dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
}
