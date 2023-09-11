
#pragma once

#include "AForm.hpp"

class Intern {

public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();
	AForm *makeForm(std::string formName, std::string target);
};
