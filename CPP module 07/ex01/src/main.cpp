#include "../includes/iter.hpp"


int main( void ) {
    
    int intArr[] = {1, 2, 3};
    std::string stringArr[] = {"a", "b", "c"};
    double doubleArr[] = {1.0, 2.0, 3.0};


    int len = 3;

    ::iter(intArr, len, testPrint<int>);
    std::cout << std::endl;
    ::iter(stringArr, len, testPrint<std::string>);
    std::cout << std::endl;
    ::iter(doubleArr, len, testPrint<double>);

    return 0;
}
