#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* actualWrongCat = new WrongCat();

	std::cout << std::endl;

	wrongCat->makeSound(); //will output the wrongAnimal sound
	wrongAnimal->makeSound();
	actualWrongCat->makeSound();

	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;
	delete actualWrongCat;

	return 0;
}