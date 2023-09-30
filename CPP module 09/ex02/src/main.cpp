#include "PmergeMe.hpp"

void printSequence(const char* message, const std::vector<int>& sequence) {
    std::cout << message;
    for (size_t i = 0; i < sequence.size(); i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void printDeque(const char* message, const std::deque<int>& deq) {
    std::cout << message;
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 0;
    }

    // Check if the input sequence is valid
    if (!PmergeMe::isSequenceValid(argc - 1, ++argv)) {
        return 0;
    }

    // Initialize a vector and a deque with the input sequence
    std::vector<int> vector;
    std::deque<int> dequeInt;

    for (int i = 0; i < argc - 1; i++) {
        int value = std::atoi(argv[i]);
        dequeInt.push_back(value);
        vector.push_back(value);
    }

    // Print the original sequence
    printSequence("Before: ", vector);

    // Sort and measure time for deque
    clock_t startTimeDeque = clock();
    PmergeMe::dequeSort(dequeInt, 0, dequeInt.size() - 1);
    clock_t endTimeDeque = clock();

    double elapsedTimeDeque = static_cast<double>(endTimeDeque - startTimeDeque) / CLOCKS_PER_SEC * 1000000.0;

    // Check if the deque is sorted
    if (!PmergeMe::isDequeSorted(dequeInt)) {
        std::cout << "Error: deque is not sorted" << std::endl;
        return 0;
    }
    // Print the sorted deque and the time taken
    printDeque("After: ", dequeInt);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << elapsedTimeDeque << " microseconds" << std::endl;


    // Sort and measure time for vector
    clock_t startTimeVector = clock();
    PmergeMe::vectorSort(vector, 0, vector.size() - 1);
    clock_t endTimeVector = clock();

    double elapsedTimeVector = static_cast<double>(endTimeVector - startTimeVector) / CLOCKS_PER_SEC * 1000000.0;

    // Check if the vector is sorted
    if (!PmergeMe::isVectorSorted(vector)) {
        std::cout << "Error: vector is not sorted" << std::endl;
        return 0;
    }
    // Print the sorted vector and the time taken
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << elapsedTimeVector << " microseconds" << std::endl;


    return 0;
}
