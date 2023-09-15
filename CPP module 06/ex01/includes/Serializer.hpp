
#pragma once

# include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer {

private:
	Serializer();
	Serializer(const Serializer &serializer);

public:
	~Serializer();
	Serializer &operator= (Serializer const &other);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
