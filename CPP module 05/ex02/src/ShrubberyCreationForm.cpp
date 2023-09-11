
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("Default") {
	std::cout << "ShrubberyCreationForm created: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm created: " << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destroyed: " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), target(form.target) {
	std::cout << "ShrubberyCreationForm created: " << *this << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &form) {
	if (this != &form) {
		this->AForm::operator=(form);
	}
	return *this;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::printErrorMessage() const {
	std::cout << "Shrubbery has failed!" << std::endl;
}

void ShrubberyCreationForm::action() const {
	std::ofstream file;
	std::string tree = 	"    ^    \n"
						"   ^^^   \n"
						"  ^^^^^  \n"
						" ^^^^^^^ \n"
						"^^^^^^^^^\n"
						"   |||   \n";

	file.open((this->target + "_shrubbery").c_str());
	for (int i = 0; i < 5; i++) {
		file << tree << std::endl;
		file << std::endl;
	}
	file.close();
}
