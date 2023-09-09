#include "../includes/Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too high";
    }
};

class Bureaucrat::GradeTooLowException : public std::exception {

public:
    const char *what() const throw() {
        return "Grade is too low";
    }
};

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    std::cout << "Bureacrat created: " << getName() << " " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = grade;
    std::cout << "Bureacrat created: " << getName() << " " << getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureacrat destroyed: " << getName() << " " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
    *this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &bureaucrat) {
    if (this != &bureaucrat) {
        this->grade = bureaucrat.getGrade();
    }
    return *this;
}

const std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->grade == 1) {
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade == 150) {
        throw GradeTooLowException();
    }
    this->grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade();
    return out;
}


