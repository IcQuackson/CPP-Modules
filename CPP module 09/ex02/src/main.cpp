
#include "PmergeMe.hpp"

void printSequence(size_t len, char **seq) {
    for (size_t i = 0; i < len; i++) {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}

void printDequ(std::deque<int> deq) {
    for (size_t i = 0; i < deq.size(); i++) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    std::deque<int> dequeInt;
    std::vector<int> vector;

    if (argc <= 1) {
        std::cout << "argc: " << argc << std::endl;
        std::cout << "argv: " << argv[0] << std::endl;
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 0;
    }
    if (!PmergeMe::isSequenceValid(argc - 1, ++argv)) {
        std::cout << "Error: not valid" << std::endl;
        return (0);
    }

    clock_t startTime = clock();

    for (int i = 0; i < argc - 1; i++) {
        dequeInt.push_back(std::atoi(argv[i]));
    }
    //std::cout << "Before:   ";
    //printSequence(argc - 1, argv);

    PmergeMe::dequeSort(dequeInt, 0, dequeInt.size() - 1);
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "DEQUE Execution time: " << elapsedTime << " milliseconds" << std::endl;
    
    if (!PmergeMe::isDequeSorted(dequeInt)) {
        std::cout << "Error: not sorted" << std::endl;
        return (0);
    }

    for (int i = 0; i < argc - 1; i++) {
        vector.push_back(std::atoi(argv[i]));
    }

    
    PmergeMe::vectorSort(vector, 0, vector.size() - 1);
    endTime = clock();
    elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "VECTOR Execution time: " << elapsedTime << " milliseconds" << std::endl;
    
    if (!PmergeMe::isVectorSorted(vector)) {
        std::cout << "Error: not sorted" << std::endl;
        return (0);
    }
}
