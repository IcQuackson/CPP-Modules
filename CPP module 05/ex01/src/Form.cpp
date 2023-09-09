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
    std::cout << "Form created: " << this << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) : name(name),\
                                                                                   isSigned(isSigned),\
                                                                                   gradeToSign(gradeToSign),\
                                                                                   gradeToExecute(gradeToExecute) {
        std::cout << "Form created: " << this << std::endl;
}

Form::~Form() {
    std::cout << "Form destroyed: " << this << std::endl;
}

/* const std::string getName() const {

}

bool getIsSigned() const;
int getGradeToSign() const;
int getGradeToExecute() const; */

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << getName() << " isSigned: " << getIsSigned() <<\
    "gradeToSign: " << getGradeToSign() <<\
    "gradeToExecute: " << getGradeToExecute();

    return out;
}