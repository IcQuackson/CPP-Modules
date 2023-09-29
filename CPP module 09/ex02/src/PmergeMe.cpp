
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

void PmergeMe::vectorInsertionSort(std::vector<int>& vec, size_t p, size_t q) {
    for (size_t i = p; i < q; i++) {
        int tempVal = vec[i + 1];
        size_t j = i + 1;
        while (j > p && vec[j - 1] > tempVal) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tempVal;
    }
}

void PmergeMe::vectorMerge(std::vector<int>& vec, size_t p, size_t q, size_t r) {
    size_t n1 = q - p + 1;
    size_t n2 = r - q;
    std::vector<int> leftVector(vec.begin() + p, vec.begin() + q + 1);
    std::vector<int> rightVector(vec.begin() + q + 1, vec.begin() + r + 1);

    size_t leftIndex = 0;
    size_t rightIndex = 0;
    for (size_t i = p; i <= r; i++) {
        if (rightIndex == n2) {
            vec[i] = leftVector[leftIndex];
            leftIndex++;
        } else if (leftIndex == n1) {
            vec[i] = rightVector[rightIndex];
            rightIndex++;
        } else if (rightVector[rightIndex] > leftVector[leftIndex]) {
            vec[i] = leftVector[leftIndex];
            leftIndex++;
        } else {
            vec[i] = rightVector[rightIndex];
            rightIndex++;
        }
    }
}

void PmergeMe::vectorSort(std::vector<int>& vec, size_t p, size_t r) {
    if (r - p > K) {
        size_t q = (p + r) / 2;
        vectorSort(vec, p, q);
        vectorSort(vec, q + 1, r);
        vectorMerge(vec, p, q, r);
    } else {
        vectorInsertionSort(vec, p, r);
    }
}

bool PmergeMe::isVectorSorted(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}