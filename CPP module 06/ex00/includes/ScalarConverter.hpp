
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

#define INT_MIN_STR "-2147483648"
#define INT_MAX_STR "2147483647"
#define INT_PLUS_MAX_STR "+2147483647"

class ScalarConverter {

private:
	static bool isChar(std::string literal);
	static bool isInt(std::string literal);
	static bool isFloat(std::string literal);
	static bool isPseudo(std::string literal);
	static void printCharConversion(std::string literal);
	static std::string intToChar(int num);

	ScalarConverter();
	ScalarConverter(ScalarConverter const &other);

public:
	ScalarConverter &operator=(ScalarConverter const &other);
	~ScalarConverter();
	
	static void convert(const std::string &literal);
};
