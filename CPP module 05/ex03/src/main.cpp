#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main() {
	{
		Bureaucrat b1("B1", 1);
		Intern someRandomIntern;
		AForm* rrf;

		{
			std::cout << std::endl;
			rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
			std::cout << std::endl;
			b1.signForm(*rrf);
			std::cout << std::endl;
			b1.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
			std::cout << std::endl;
		}
		{
			std::cout << std::endl;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << std::endl;
			b1.signForm(*rrf);
			std::cout << std::endl;
			b1.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
			std::cout << std::endl;
		}
		{
			std::cout << std::endl;
			rrf = someRandomIntern.makeForm("presidential request", "Bender");
			std::cout << std::endl;
			b1.signForm(*rrf);
			std::cout << std::endl;
			b1.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
			std::cout << std::endl;
		}
		{
			std::cout << std::endl;
			rrf = someRandomIntern.makeForm("invalid", "Bender");
		}
	}

}
