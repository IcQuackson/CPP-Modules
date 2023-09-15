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
	std::cout << "'" << static_cast<char>(character) << "'" << std::endl;
	std::cout << "int: ";
	std::cout << static_cast<int>(character) << std::endl;
	std::cout << "float: ";
	std::cout << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(character) << ".0" << std::endl;
}

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

std::string ScalarConverter::intToChar(int num, std::string charConversion) {
	if (charConversion == "" && (num >= 32 && num <= 126)) {
		charConversion = "'";
		charConversion += static_cast<char>(num);
		charConversion += "'";
	}
	else if (charConversion == "") {
		charConversion = "Non displayable";
	}
	return charConversion;
}

bool ScalarConverter::isZero(std::string literal) {
	int dotCount = 0;
	size_t i;
	
	i = 0;
	// check for sign
	if (literal.length() > 1 && (literal[0] == '+' || literal[0] == '-')) {
		i++;
	}
	// check for multiple dots
	for (; i < literal.length(); i++) {
	 	if (literal[i] == '.') {
	 		dotCount++;
		}
	}
	if (dotCount > 1) {
		return false;
	}
	// check for any form of zero (0...., 0..0....., 0000...0000f)
	i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
	for (; i < literal.length(); i++) {
		if (literal[i] == '.') {
			continue;
		}
		if (literal[i] != '0') {
			break;
		}
	}
	if (i == literal.length()) {
		return true;
	}
	return i == (literal.length() - 1) && literal[i] == 'f';
}

int ScalarConverter::getNumDigits(double num) {
	int numDigits = 0;

	if ((num < INFINITY && num > -INFINITY && num != NAN)) {
		if (num == 0 || floor(num) != num) {
			return -1;
		}
		if (num < 0) {
			num *= -1.0;
		}
		while (num >= 1) {
			num = floor(num / 10.0);
			numDigits++;
		}

		return numDigits;
	}
	else {
		return -1;
	}
}

bool ScalarConverter::isPseudoDouble(double num) {
	return num == INFINITY || num == -INFINITY || num == NAN;
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
		doubleConversion = std::strtod(literal.c_str(), NULL);
		floatConversion = static_cast<float>(doubleConversion);
	}
	
	if (isPseudo(literal)) {
		charConversion = "impossible";
	}
	// check for impossible conversion
	if (!isZero(literal) && intConversion == 0
	&& charConversion == "" && doubleConversion == 0
	&& floatConversion == 0) {
		std::cout << "Impossible conversion!" << std::endl;
		return;
	}

	charConversion = intToChar(intConversion, charConversion);
	std::cout << "char: " << charConversion << std::endl;

	if (charConversion == "impossible") {
		std::cout <<"int: " << "impossible" << std::endl;  
	}
	else {
		std::cout << "int: " << intConversion << std::endl;
	}

	if (charConversion == "impossible" && floatConversion == 0) {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	/* Checks if prints the float and double conversions
	with or without decimal places. */
	int numDigits = getNumDigits(doubleConversion);
	if (!isPseudoDouble(doubleConversion) && charConversion != "impossible" && (floor(doubleConversion) == doubleConversion
	&& (isZero(literal) || (numDigits != -1 && numDigits < 7)))) {
		std::cout << "float: " << floatConversion << ".0f" << std::endl;
		std::cout << "double: " << doubleConversion << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << floatConversion << "f" << std::endl;
		std::cout << "double: " << doubleConversion << std::endl;
	}
}
