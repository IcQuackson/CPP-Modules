
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void) other;
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isSequenceValid(int len, char **seq) {

	for (int i = 0; i < len; i++) {
		int strLen = std::strlen(seq[i]);

		if (strLen > 10) {
			std::cout << "PmergeMe::isSequenceValid: sequence too long: " << seq[i] << std::endl;
			return false;
		}
		if (strLen == 10 && std::strcmp(seq[i], INT_MAX)) {
			std::cout << "PmergeMe::isSequenceValid: int max: " << seq[i] << std::endl;
			return false;
		}
		if (std::atoi(seq[i]) <= 0) {
			std::cout << "PmergeMe::isSequenceValid: zero: " << seq[i] << std::endl;
			return false;
		}
	}
	return true;
}

const int K = 5;

void PmergeMe::dequeInsertionSort(std::deque<int>& deq, int p, int q) {
	for (int i = p; i < q; i++) {
		int tempVal = deq[i + 1];
		int j = i + 1;
		while (j > p && deq[j - 1] > tempVal) {
			deq[j] = deq[j - 1];
			j--;
		}
		deq[j] = tempVal;
	}
}

void PmergeMe::dequeMerge(std::deque<int>& deq, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::deque<int> leftDeque(deq.begin() + p, deq.begin() + q + 1);
	std::deque<int> rightDeque(deq.begin() + q + 1, deq.begin() + r + 1);

	int leftIndex = 0;
	int rightIndex = 0;
	for (int i = p; i <= r; i++) {
		if (rightIndex == n2) {
			deq[i] = leftDeque[leftIndex];
			leftIndex++;
		} else if (leftIndex == n1) {
			deq[i] = rightDeque[rightIndex];
			rightIndex++;
		} else if (rightDeque[rightIndex] > leftDeque[leftIndex]) {
			deq[i] = leftDeque[leftIndex];
			leftIndex++;
		} else {
			deq[i] = rightDeque[rightIndex];
			rightIndex++;
		}
	}
}

void PmergeMe::dequeSort(std::deque<int>& deq, int p, int r) {
	if (r - p > K) {
		int q = (p + r) / 2;
		dequeSort(deq, p, q);
		dequeSort(deq, q + 1, r);
		dequeMerge(deq, p, q, r);
	} else {
		dequeInsertionSort(deq, p, r);
	}
}

bool PmergeMe::isDequeSorted(std::deque<int>& deq) {
	for (size_t i = 0; i < deq.size() - 1; i++) {
        if (deq[i] > deq[i + 1]) {
            return false;
        }
    }
    return true;
}

void PmergeMe::listInsertionSort(std::list<int>& lst) {
    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i) {
        std::list<int>::iterator j = i;
        ++j;
        if (j == lst.end()) {
            break;
        }
        int tempVal = *j;
        while (j != lst.begin()) {
            std::list<int>::iterator prevJ = j;
            --prevJ;
            if (*prevJ > tempVal) {
                *j = *prevJ;
                --j;
            } else {
                break;
            }
        }
        *j = tempVal;
    }
}

void PmergeMe::listMerge(std::list<int>& lst, std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r) {
    std::list<int> mergedList;

    std::list<int>::iterator leftIter = p;
    std::list<int>::iterator rightIter = q;

    while (leftIter != q && rightIter != r) {
        if (*rightIter < *leftIter) {
            lst.insert(p, *rightIter);
            ++rightIter;
        } else {
            lst.insert(p, *leftIter);
            ++leftIter;
        }
        ++p; // Move the iterator in the original list
    }

    // Copy the remaining elements from the left and right halves
    lst.insert(p, leftIter, q);
    lst.insert(p, rightIter, r);
}


void PmergeMe::listSort(std::list<int>& lst) {
    if (lst.size() > K) {
        std::list<int> secondHalf;
        std::list<int>::iterator p = lst.begin();
        std::advance(p, lst.size() / 2);

        std::copy(p, lst.end(), std::back_inserter(secondHalf));
        lst.erase(p, lst.end());

        listSort(lst);
        listSort(secondHalf);
        listMerge(lst, lst.begin(), secondHalf.begin(), secondHalf.end());
    }
	else {
        listInsertionSort(lst);
    }
}

bool PmergeMe::isListSorted(const std::list<int>& lst) {
    std::list<int>::const_iterator it1 = lst.begin();
    std::list<int>::const_iterator it2 = lst.begin();
    ++it2;

    while (it2 != lst.end()) {
        if (*it1 > *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}
