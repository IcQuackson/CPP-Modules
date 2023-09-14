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
	return literal.size() == 1 &&
	((literal[0] >= 'a' && literal[0] <= 'z') ||
	 (literal[0] >= 'A' && literal[0] <= 'Z'));
}

void ScalarConverter::printCharConversion(std::string literal) {
	char character = literal[0];
	std::cout << "char: "; 
	std::cout << static_cast<char>(character) << std::endl;
	std::cout << "int: ";
	std::cout << static_cast<int>(character) << std::endl;
	std::cout << "float: ";
	std::cout << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(character) << ".0" << std::endl;
}

/* void ScalarConverter::printIntConversion(std::string literal) {

} */

bool ScalarConverter::isPseudo(std::string literal) {
	std::string pseudoLiterals[] = {"-inf", "+inf", "-inff", "+inff", "nan", "nanf"};

	for (int i = 0; i < 6; i++) {
		if (pseudoLiterals[i] == literal) {
			return true;
		}
	}
	return false;
}

bool ScalarConverter::isFloat(std::string literal) {
	return literal[literal.length() - 1] == 'f';
}

std::string ScalarConverter::intToChar(int num) {
	std::string charConversion;

	charConversion = static_cast<char>(num);
	if (num < 32 || num > 126) {
		charConversion = "Non displayable";
	}
	else {
		charConversion = "'";
		charConversion += static_cast<char>(num);
		charConversion += "'";
	}
	return charConversion;
}

void ScalarConverter::convert(const std::string &literal) {

	std::string charConversion = "";
	int intConversion = 0;
	float floatConversion = 0;
	double doubleConversion = 0;

	if ((isChar(literal))) {
		printCharConversion(literal);
		return;
	}
	intConversion = std::atoi(literal.c_str());

	if (isFloat(literal)) {
		floatConversion = std::atof(literal.c_str());
		doubleConversion = static_cast<double>(floatConversion);
	}
	else {
		doubleConversion = std::atof(literal.c_str());
		floatConversion = static_cast<float>(doubleConversion);
	}
	if (isPseudo(literal)) {
		charConversion = "impossible";
	}
	else {
		charConversion = intToChar(intConversion);
	}
	std::cout << "char: ";
	if (intConversion < 32 || intConversion > 126) {
		std::cout << "Non displayable" << std::endl;
	}
	else {
		std::cout << static_cast<char>(intConversion) << std::endl;
	}
	if (charConversion == "impossible") {
		
	}
	std::cout <<"int: " << intConversion << std::endl;
	std::cout << "float: " << floatConversion << ".0f" << std::endl;
	std::cout << "double: " << doubleConversion << ".0" << std::endl;

	/* 
	else {
		std::cout << "No conversion possible" << std::endl;
	} */
}
