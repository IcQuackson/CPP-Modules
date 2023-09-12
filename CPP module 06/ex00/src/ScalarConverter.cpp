#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void) other;
	return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	*this = other;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(std::string literal) {
	if (literal.length() == 1) {
		if (!std::isprint(literal[0])) {
			std::cout << "Conversion to char is not displayable!";
			return false;
		}
		return std::isalpha(literal[0]);
	}
	return false;
}

void ScalarConverter::convert(std::string literal) {
	/* char charRepresentation;
	int  intRepresentation;
	float floatRepresentation;
	double doubleRepresentation; */

	if (isChar(literal)) {
		std::cout << literal << std::endl;;
	}
	else {
		std::cout << "Conversion is not possible to any type" << std::endl;
	}
}