
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

template <class T>
class MutantStack : public std::stack<T, std::deque<T> > {

public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack<T> &other);
    MutantStack &operator= (const MutantStack<T> &other);

    typedef typename std::deque<T>::iterator iterator;
    void push(const T& value);
    void pop();
    iterator begin();
    iterator end();
};

#include "../src/MutantStack.tpp"

#endif