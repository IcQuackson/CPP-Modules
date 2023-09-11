
#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException;
    class GradeTooLowException;

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator= (const Bureaucrat &bureaucrat);

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
	void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
