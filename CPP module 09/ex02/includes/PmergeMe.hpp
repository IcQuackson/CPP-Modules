
#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <cstring>
#include <ctime>

#define INT_MAX "2147483647"

class PmergeMe {

private:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

public:
    /* static std::deque<int> dequeMergeInsertionSort(std::deque<int> &deq);
    static std::deque<int> mergeDeques(std::deque<std::deque<int> > &pairs);
    static void dequeInsertionSort(std::deque<int> &subArray, size_t begin, size_t len); */
    static bool isSequenceValid(int len, char **seq);
    static void dequeSort(std::deque<int>& deq, int p, int r);
    static void dequeInsertionSort(std::deque<int>& deq, int p, int q);
    static void dequeMerge(std::deque<int>& deq, int p, int q, int r);
    static bool isDequeSorted(std::deque<int>& deq);

	static void listInsertionSort(std::list<int>& lst);
	static void listMerge(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r);
	static void listSort(std::list<int>& lst);
	static bool isListSorted(const std::list<int>& lst);
};
