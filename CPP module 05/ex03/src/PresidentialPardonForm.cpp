#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), target("Default") {
	std::cout << "PresidentialPardonForm created: " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), target(target) {
	std::cout << "PresidentialPardonForm created: " << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destroyed: " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), target(form.target) {
	std::cout << "PresidentialPardonForm created: " << *this << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &form) {
	if (this != &form) {
		this->AForm::operator=(form);
	}
	return *this;
}

const std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::action() const {
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::printErrorMessage() const {
	std::cout << "Presidential pardon has failed!" << std::endl;
}
