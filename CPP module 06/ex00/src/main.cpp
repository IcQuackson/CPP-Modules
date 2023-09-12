
#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Program requires 1 argument!" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}
