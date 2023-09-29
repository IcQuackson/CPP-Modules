
#pragma once

#include <iostream>
#include <deque>
#include <vector>
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

    static void vectorInsertionSort(std::vector<int>& vec, size_t p, size_t q);
    static void vectorMerge(std::vector<int>& vec, size_t p, size_t q, size_t r);
    static void vectorSort(std::vector<int>& vec, size_t p, size_t r);
    static bool isVectorSorted(const std::vector<int>& vec);
};
