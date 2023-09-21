
#include "Span.hpp"

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

/**
 * The addNumber function adds a number to the vector if it is not already full.
 * 
 * @param num The parameter "num" is an integer value that represents the number to be added to the
 * vector.
 */
void Span::addNumber(int num) {
	if (this->vector.size() == maxSize) {
		throw std::runtime_error("Storage is full!");
	}
	vector.push_back(num);
}

/**
 * The function adds a range of numbers to a vector, throwing an error if the vector exceeds its
 * maximum size.
 * 
 * @param begin An iterator pointing to the beginning of the range of numbers to be added to the
 * vector.
 * @param end The "end" parameter is an iterator pointing to the position of the last element in
 * the range of numbers that you want to add to the "vector" member variable of the "Span" class.
 */
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->vector.size() + std::distance(begin, end) > maxSize) {
		throw std::runtime_error("Storage is full!");
	}
	vector.insert(vector.end(), begin, end);
}

/**
 * The function calculates the shortest span between two elements in a vector.
 * First it sorts the vector, then it iterates through the vector and compares
 * the difference between the current element and the next element.
 * If the difference is smaller than the current shortest span, the difference becomes
 * the new shortest span.
 * 
 * @return the shortest span between elements in the vector.
 */
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

/**
 * The function calculates the difference between the maximum and minimum elements in a vector.
 * 
 * @return the difference between the maximum and minimum elements in the vector.
 */
int Span::longestSpan() const {

	if (this->vector.size() <= 1) {
		throw std::runtime_error("Not enough elements to calculate longest span!");
	}

	return *std::max_element(this->vector.begin(), this->vector.end())
		 - *std::min_element(this->vector.begin(), this->vector.end());
}
