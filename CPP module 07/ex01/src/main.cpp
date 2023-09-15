#include "../includes/iter.hpp"


void printTwice(std::string &s) 
{
    std::cout << s << s << std::endl;
}

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
    std::cout << std::endl;
    ::iter(stringArr, len, printTwice);

    return 0;
}
