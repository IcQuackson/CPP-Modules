#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat& WrongCat::operator= (const WrongCat &wrongCat) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &wrongCat) {
        this->type = wrongCat.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "MEOWWWWWWW" << std::endl;
}