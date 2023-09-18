#include "../includes/easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
	// test
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	std::cout << easyfind(vector, 3) << std::endl; // Should print 1
	std::cout << easyfind(vector, 6) << std::endl; // Should print 0
	return 0;
}