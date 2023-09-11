
#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	const std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &form);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &form);

	const std::string getTarget() const;
	void action() const;
	void printErrorMessage() const;
};
