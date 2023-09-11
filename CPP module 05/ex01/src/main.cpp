#include "../includes/Bureaucrat.hpp"

int main() {
    Bureaucrat b1 = Bureaucrat();
    Bureaucrat b2 = Bureaucrat("Antonio Costa", 150);

	std::cout << std::endl;

	try {
		Form test = Form("atestado de residencia", false, 0, 40);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form test = Form("atestado de residencia", false, 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Form f1 = Form("atestado de residencia", false, 149, 40);
	
	std::cout << std::endl;

	b2.signForm(f1);

	std::cout << std::endl;

	b2.incrementGrade();
	b2.signForm(f1);
	std::cout << std::endl;

	b2.decrementGrade();
	b2.signForm(f1);
	std::cout << std::endl;
}
