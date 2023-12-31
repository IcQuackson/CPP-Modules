
#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &serializer) {
	*this = serializer;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator= (Serializer const &other) {
	if (this != &other) {}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
