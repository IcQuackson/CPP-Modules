
#include "../includes/Serializer.hpp"

int main() {
	Data src = {1, 2};

	std::cout << "src.id: " << src.id << std::endl;
	std::cout << "src.value: " << src.value << std::endl;

	uintptr_t raw = Serializer::serialize(&src);
	Data *dest = Serializer::deserialize(raw);

	std::cout << "<=====================================>" << std::endl;

	std::cout << "dest->id: " << dest->id << std::endl;
	std::cout << "dest->value: " << dest->value << std::endl;

	std::cout << "address is the same?: " << (&src == dest) << std::endl;
}
