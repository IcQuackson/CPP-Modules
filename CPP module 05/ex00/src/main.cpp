#include "../includes/Bureaucrat.hpp"

int main() {
    Bureaucrat b1 = Bureaucrat();
    Bureaucrat b2 = Bureaucrat("Antonio Costa", 149);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    b2.decrementGrade();
    std::cout << b2 << std::endl;
    b2.incrementGrade();
    std::cout << b2 << std::endl;

    std::cout << std::endl;

    try {
        Bureaucrat b3 = Bureaucrat("b3", 0); // throws GradeTooHighException
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try {
        Bureaucrat b4 = Bureaucrat("b4", 151); // throws GradeTooLowException
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    b2.decrementGrade();

    try {
        b2.decrementGrade(); // throws GradeTooLowException
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try {
        Bureaucrat mafiaBoss = Bureaucrat("Mafia Boss", 1);
        mafiaBoss.incrementGrade(); // throws GradeTooHighException
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
