#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(Intern const &other) {
	if (this != &other) {}
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm *createPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *createRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *createShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm *form = NULL;
	std::string formNames[] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};
	AForm* (*constructors[])(std::string target) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			form = constructors[i](target);
			std::cout << "Intern creates " << *form << std::endl;
			return form;
		}
	}
	std::cout << "Intern could not create form" << std::endl;
	return NULL;
}
