#include "../includes/AForm.hpp"

class AForm::GradeTooHighException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too high";
    }
};

class AForm::GradeTooLowException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too low";
    }
};

class AForm::FormNotSignedException : public std::exception {

public:
	const char *what() const throw() {
		return "Form is not signed";
	}
};

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm created: " << *this << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : name(name),\
                                                                                   isSigned(isSigned),\
                                                                                   gradeToSign(gradeToSign),\
                                                                                   gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
	std::cout << "AForm created: " << *this << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm destroyed: " << *this << std::endl;
}

AForm::AForm(const AForm &form) : name(form.name), isSigned(form.isSigned),\
							   gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	std::cout << "AForm created: " << *this << std::endl;
}

AForm &AForm::operator= (const AForm &form) {
	if (this != &form) {
		this->isSigned = form.isSigned;
	}
	return *this;
}

const std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const { 
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	
		if (executor.getGrade() > this->getGradeToExecute()) {
			throw GradeTooLowException();
		}
		if (!this->getIsSigned()) {
			throw FormNotSignedException();
		}
}

void AForm::printErrorMessage() const {
	std::cout << "Error" << *this << std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName() << "; isSigned: " << form.getIsSigned() <<\
    "; gradeToSign: " << form.getGradeToSign() <<\
    "; gradeToExecute: " << form.getGradeToExecute();

    return out;
}