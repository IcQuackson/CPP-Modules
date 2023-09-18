
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    (void) argv;

    if (argc != 2) {
        std::cout << "Error: could not open file"<< std::endl;
        return 0;
    }
    BitcoinExchange bitcoinExchange(argv[1]);
    bitcoinExchange.printRecords();
    return 0;
}