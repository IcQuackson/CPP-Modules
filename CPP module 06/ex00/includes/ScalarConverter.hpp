
#pragma once

#include <iostream>
#include <string>

class ScalarConverter {

private:
	static bool isChar(std::string literal);
	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static bool isDouble(std::string literal);
	static int	toInt(std::string literal);

public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
	
	static void convert(std::string literal);
	static void printCharConversion(std::string literal);
	static void printIntConversion(std::string literal);
	static void printFloatConversion(std::string literal);
	static void printDoubleConversion(std::string literal);
};
