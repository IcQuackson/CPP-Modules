
#include "../includes/Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::~Span() {}

Span::Span(Span const &other) {
	*this = other;
}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		this->maxSize = other.maxSize;
		this->vector = other.vector;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (this->vector.size() == maxSize) {
		throw std::runtime_error("Storage is full!");
	}
	vector.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->vector.size() + std::distance(begin, end) > maxSize) {
		throw std::runtime_error("Storage is full!");
	}
	vector.insert(vector.end(), begin, end);
}

int Span::shortestSpan() const{
	int currentSize;
	int shortestSpan;
	int currentSpan;

	if (this->vector.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate shortest span!");
	}

	std::vector<int> sortedVector = this->vector;
	std::sort(sortedVector.begin(), sortedVector.end());

	shortestSpan = abs(sortedVector.at(1) - sortedVector.at(0));
	currentSize = sortedVector.size();

	for (int i = 1; i < currentSize - 1; i++) {
		currentSpan = abs(sortedVector.at(i + 1) - sortedVector.at(i));
		if (currentSpan < shortestSpan) {
			shortestSpan = currentSpan;
		}
	}
	return shortestSpan;
}

int Span::longestSpan() const {

	if (this->vector.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate longest span!");
	}

	return *std::max_element(this->vector.begin(), this->vector.end())
		 - *std::min_element(this->vector.begin(), this->vector.end());
}
