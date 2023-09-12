
#pragma once

#include <iostream>

class ScalarConverter {

private:
	static bool isChar(std::string literal);
	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static bool isDouble(std::string literal);

public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
	
	static void convert(std::string literal);
};
