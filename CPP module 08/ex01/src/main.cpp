#include "../includes/Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <time.h>

int main() {
	{
		// Normal usage
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// Empty storage
		Span sp = Span(10000);

		srand(time(NULL));
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(rand());
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		// Storage is full
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try {
			sp.addNumber(3);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(1);
		sp.addNumber(1);
		// Not enough elements to calculate shortest span
		try {
			sp.shortestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		// Not enough elements to calculate longest span
		try {
			sp.longestSpan();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
