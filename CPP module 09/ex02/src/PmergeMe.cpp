
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

/* void PmergeMe::listInsertionSort(std::list<int>& lst) {
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

void PmergeMe::listMerge(std::list<int>::iterator p, std::list<int>::iterator q, std::list<int>::iterator r) {
    std::list<int> leftList(p, q);
    std::list<int> rightList(q, r);

    std::list<int>::iterator leftIter = leftList.begin();
    std::list<int>::iterator rightIter = rightList.begin();
    std::list<int>::iterator mainIter = p;

    while (leftIter != leftList.end() && rightIter != rightList.end()) {
        if (*rightIter < *leftIter) {
            *mainIter = *rightIter;
            ++rightIter;
        } else {
            *mainIter = *leftIter;
            ++leftIter;
        }
        ++mainIter;
    }

    while (leftIter != leftList.end()) {
        *mainIter = *leftIter;
        ++leftIter;
        ++mainIter;
    }

    while (rightIter != rightList.end()) {
        *mainIter = *rightIter;
        ++rightIter;
        ++mainIter;
    }
}

void PmergeMe::listSort(std::list<int>& lst) {
    if (lst.size() > K) {
        std::list<int>::iterator p = lst.begin();
        std::advance(p, lst.size() / 2);
        std::list<int>::iterator q = p;
        std::list<int>::iterator r = lst.end();
        listSort(lst);
        listSort(lst);
        listMerge(p, q, r);
    } else {
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
} */

bool PmergeMe::isDequeSorted(std::deque<int>& deq) {
	for (size_t i = 0; i < deq.size() - 1; i++) {
        if (deq[i] > deq[i + 1]) {
            return false;
        }
    }
    return true;
}
