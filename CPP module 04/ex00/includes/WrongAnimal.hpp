#include <iostream>

class WrongAnimal {

protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &wrongAnimal);
    WrongAnimal &operator= (const WrongAnimal &wrongAnimal);
    virtual ~WrongAnimal();

	std::string getType() const;
    void makeSound() const;
};
