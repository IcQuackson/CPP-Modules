
#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "../includes/MutantStack.hpp"

template <class T>
class MutantStack;

template <class T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T> >() {
}

template <class T>
MutantStack<T>::~MutantStack() {
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) {
	*this = other;
}

template <class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return std::stack<T>::c.begin();
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return std::stack<T>::c.end();
}


#endif