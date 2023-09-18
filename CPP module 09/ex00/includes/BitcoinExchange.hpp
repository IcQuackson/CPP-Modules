
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class BitcoinExchange {

private:
    static const char *dbFileName;
    std::vector<std::string> inputContent;
    std::vector<std::string> dbContent;

    void storeContent(const char *fileName,
                                std::vector<std::string> &vector);
    bool isInputValid() const;
    bool isLineValid(std::string line) const;
    bool isFormatValid(const std::string& line) const;
    bool isDateValid(const std::string& line) const;
    double getValue(const std::string& line) const;
    double getRate(const std::string& line) const;

public:
    BitcoinExchange();
    BitcoinExchange(char *infileName);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    
    void printRecords() const;
};
