#include "Span.hpp"

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
		Span sp = Span(15000);

		std::vector<int> vector(15000);

		for (int i = 0; i < 15000; i++) {
			vector.at(i) = i;
		}
		// usage of range of iterators
		sp.addNumber(vector.begin(), vector.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try {
			sp.addNumber(3);
		}
		catch (std::exception &e) {
			std::cout << "range of iterators: " << e.what() << std::endl;
		}
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
