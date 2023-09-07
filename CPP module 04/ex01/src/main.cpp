#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j; //should not create a leak
	delete i;

	std::cout << std::endl;

	Animal *animal_arr[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			animal_arr[i] = new Dog();
		}
		else {
			animal_arr[i] = new Cat();
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		delete animal_arr[i];
	}

	std::cout << std::endl;

	// A copy of a Dog or a Cat mustn’t be shallow.
	Dog *originalDog = new Dog();
    Dog copiedDog = *originalDog;
    Dog copiedDog2 = Dog(*originalDog);

	std::cout << std::endl;

	std::cout << originalDog->getBrain() << std::endl;
	delete originalDog;
	std::cout << copiedDog.getBrain() << std::endl;
	std::cout << copiedDog2.getBrain() << std::endl;

	std::cout << std::endl;

	Cat *originalCat = new Cat();
    Cat copiedCat = *originalCat;
    Cat copiedCat2 = Cat(*originalCat);

	std::cout << std::endl;

	std::cout << originalCat->getBrain() << std::endl;
	delete originalCat;
	std::cout << copiedCat.getBrain() << std::endl;
	std::cout << copiedCat2.getBrain() << std::endl;

	std::cout << std::endl;

	return 0;
}