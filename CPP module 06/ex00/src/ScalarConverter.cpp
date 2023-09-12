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
	return literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

int ScalarConverter::toInt(std::string literal) {
	return static_cast<int>(literal.c_str()[0]);
}

void ScalarConverter::printCharConversion(std::string literal) {
	if (literal.length() == 1) {
		char character = literal[0];
		std::cout << "char: "; 
		if (std::isprint(character)) {
			std::cout << static_cast<char>(character) << std::endl;
		}
		else {
			std::cout << "Non displayable" << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string literal) {
	printCharConversion(literal);

	if (isChar(literal)) {
		
	}
	//printIntConversion(literal);
	//printFloatConversion(literal);
	//printDoubleConversion(literal);
}
