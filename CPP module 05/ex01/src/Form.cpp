#include "../includes/Form.hpp"

class Form::GradeTooHighException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too high";
    }
};

class Form::GradeTooLowException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too low";
    }
};

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "Form created: " << *this << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : name(name),\
                                                                                   isSigned(isSigned),\
                                                                                   gradeToSign(gradeToSign),\
                                                                                   gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
	std::cout << "Form created: " << *this << std::endl;
}

Form::~Form() {
    std::cout << "Form destroyed: " << *this << std::endl;
}

Form::Form(const Form &form) : name(form.name), isSigned(form.isSigned),\
							   gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	std::cout << "Form created: " << *this << std::endl;
}

Form &Form::operator= (const Form &form) {
	if (this != &form) {
		this->isSigned = form.isSigned;
	}
	return *this;
}

const std::string Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const { 
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName() << "; isSigned: " << form.getIsSigned() <<\
    "; gradeToSign: " << form.getGradeToSign() <<\
    "; gradeToExecute: " << form.getGradeToExecute();

    return out;
}