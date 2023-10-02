
#include "PmergeMe.hpp"

const int K = 7;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    (void) other;
    return *this;
}

PmergeMe::~PmergeMe() {}

/**
 * Checks if a sequence of strings is valid based on certain criteria.
 *
 * @param len The length of the sequence.
 * @param seq The sequence of strings to be validated.
 * @return    True if the sequence is valid, false otherwise.
 */
bool PmergeMe::isSequenceValid(int len, char **seq) {
    if (len == 0) {
        return false;
    }
    // Iterate through each string in the sequence
    for (int i = 0; i < len; i++) {
        // Get the length of the current string
        int strLen = std::strlen(seq[i]);

        if (std::string(seq[i]).find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Error: non numeric or invalid argument: " << seq[i] << std::endl;
            return false;
        }

        // Check if the string is too long
        if (strLen > 10) {
            std::cout << "Error: sequence too long" << std::endl;
            return false;
        }

        // Check if the string is equal to "INT_MAX"
        if (strLen == 10 && std::strcmp(seq[i], "INT_MAX") == 0) {
            std::cout << "Error: int max: " << seq[i] << std::endl;
            return false;
        }

        // Check if the string can be converted to a positive integer
        if (std::atoi(seq[i]) <= 0) {
            std::cout << "Error: zero or invalid integer: " << seq[i] << std::endl;
            return false;
        }
    }

    // Print the sequence
    std::cout << "Before: ";
    for (int i = 0; i < len; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;

    return true;
}


/**
 * Sorts a subarray of a deque using the insertion sort algorithm.
 *
 * @param deq The deque containing the subarray to be sorted.
 * @param p   The starting index of the subarray to be sorted.
 * @param q   The ending index of the subarray to be sorted.
 */
void PmergeMe::dequeInsertionSort(std::deque<int>& deq, int p, int q) {
    // Insertion sort algorithm for a deque
    for (int i = p; i < q; i++) {
        // Store the value to be inserted
        int tempVal = deq[i + 1];
        // Initialize the index for comparison
        int j = i + 1;

        // Move elements greater than tempVal to the right
        while (j > p && deq[j - 1] > tempVal) {
            deq[j] = deq[j - 1];
            j--;
        }

        // Insert tempVal into the correct position
        deq[j] = tempVal;
    }
}

/**
 * Merges two sorted subarrays of a deque into a single sorted subarray.
 *
 * @param deq The deque containing the subarrays to be merged.
 * @param p   The starting index of the first subarray.
 * @param q   The ending index of the first subarray (exclusive).
 * @param r   The ending index of the second subarray.
 */
void PmergeMe::dequeMerge(std::deque<int>& deq, int p, int q, int r) {
    // Calculate the sizes of the two subarrays to be merged
    int n1 = q - p + 1;
    int n2 = r - q;

    // Create temporary deques for the left and right subarrays
    std::deque<int> leftDeque(deq.begin() + p, deq.begin() + q + 1);
    std::deque<int> rightDeque(deq.begin() + q + 1, deq.begin() + r + 1);

    // Merge the two sorted subarrays
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

/**
 * Sorts a subarray of a deque using the merge sort algorithm.
 *
 * @param deq The deque containing the subarray to be sorted.
 * @param p   The starting index of the subarray to be sorted.
 * @param r   The ending index of the subarray to be sorted. 
 */
void PmergeMe::dequeSort(std::deque<int>& deq, int p, int r) {
    // Merge sort the deque if the size of the subarray is greater than K
    if (r - p > K) {
        // Calculate the midpoint of the subarray
        int q = (p + r) / 2;

        // Recursively apply merge sort to the left and right halves
        dequeSort(deq, p, q);
        dequeSort(deq, q + 1, r);

        // Merge the sorted halves
        dequeMerge(deq, p, q, r);
    }
    // Insertion sort the deque if the size of the subarray is less than or equal to K
    else {
        dequeInsertionSort(deq, p, r);
    }
}

/**
 * Checks if a deque is sorted in ascending order.
 *
 * @param deq The deque to be checked for sorted order.
 * @return    True if the deque is sorted, false otherwise.
*/
bool PmergeMe::isDequeSorted(std::deque<int>& deq) {
	// Check if the deque is sorted in ascending order
	for (size_t i = 0; i < deq.size() - 1; i++) {
        if (deq[i] > deq[i + 1]) {
            return false;
        }
    }
    return true;
}

/**
 * Sorts a subarray of a vector using the insertion sort algorithm.
 *
 * @param vec The vector containing the subarray to be sorted.
 * @param p   The starting index of the subarray to be sorted.
 * @param q   The ending index of the subarray to be sorted.
 */
void PmergeMe::vectorInsertionSort(std::vector<int>& vec, size_t p, size_t q) {
    // Insertion sort algorithm
    for (size_t i = p; i < q; i++) {
        // Store the value to be inserted
        int tempVal = vec[i + 1];
        // Initialize the index for comparison
        size_t j = i + 1;

        // Move elements greater than tempVal to the right
        while (j > p && vec[j - 1] > tempVal) {
            vec[j] = vec[j - 1];
            j--;
        }

        // Insert tempVal into the correct position
        vec[j] = tempVal;
    }
}

/**
 * Merges two sorted subarrays of the vector into a single sorted subarray.
 *
 * @param vec The vector containing the subarrays to be merged.
 * @param p   The starting index of the subarray to be merged.
 * @param q   The ending index of the first subarray to be merged.
 * @param r   The ending index of the second subarray to be merged.
 */
void PmergeMe::vectorMerge(std::vector<int>& vec, size_t p, size_t q, size_t r) {
    // Calculate sizes of the two subarrays to be merged
    size_t n1 = q - p + 1;
    size_t n2 = r - q;

    // Create temporary vectors to hold the left and right subarrays
    std::vector<int> leftVector(vec.begin() + p, vec.begin() + q + 1);
    std::vector<int> rightVector(vec.begin() + q + 1, vec.begin() + r + 1);

    size_t leftIndex = 0;
    size_t rightIndex = 0;

    // Merge the two subarrays back into the original vector
    for (size_t i = p; i <= r; i++) {
        if (rightIndex == n2) {
            // If all elements from the right subarray are merged, use the remaining left elements
            vec[i] = leftVector[leftIndex];
            leftIndex++;
        } else if (leftIndex == n1) {
            // If all elements from the left subarray are merged, use the remaining right elements
            vec[i] = rightVector[rightIndex];
            rightIndex++;
        } else if (rightVector[rightIndex] > leftVector[leftIndex]) {
            // Compare elements from the left and right subarrays and merge in ascending order
            vec[i] = leftVector[leftIndex];
            leftIndex++;
        } else {
            vec[i] = rightVector[rightIndex];
            rightIndex++;
        }
    }
}

/**
 * Sorts a subarray of a vector using the merge sort algorithm.
 *
 * @param vec The vector containing the subarray to be sorted.
 * @param p   The starting index of the subarray to be sorted.
 * @param r   The ending index of the subarray to be sorted.
 */
void PmergeMe::vectorSort(std::vector<int>& vec, size_t p, size_t r) {
    // Merge sort the vector if the size of the subarray is greater than K
    if (r - p > K) {
        // Calculate the midpoint of the subarray
        size_t q = (p + r) / 2;

        // Recursively apply merge sort to the left and right halves
        vectorSort(vec, p, q);
        vectorSort(vec, q + 1, r);

        // Merge the sorted halves
        vectorMerge(vec, p, q, r);
    }
    // Insertion sort the vector if the size of the subarray is less than or equal to K
    else {
        vectorInsertionSort(vec, p, r);
    }
}

bool PmergeMe::isVectorSorted(const std::vector<int>& vec) {
	// Check if the vector is sorted in ascending order
    for (size_t i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            return false;
        }
    }
    return true;
}