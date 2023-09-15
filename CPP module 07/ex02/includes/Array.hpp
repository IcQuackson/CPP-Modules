
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <time.h>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <class T>
class Array {

private:
    T *array;
    unsigned int len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator= (const Array &other);
    T &operator[] (unsigned int index) const;
    ~Array();
    unsigned int size() const;
};


#include "../src/Array.tpp"

#endif
