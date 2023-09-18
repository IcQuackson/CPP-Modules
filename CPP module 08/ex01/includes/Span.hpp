
#pragma once

#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

class Span {

private:
	unsigned int maxSize;
	std::vector<int> vector;

public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(Span const &other);
	Span &operator=(Span const &other);

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;
};