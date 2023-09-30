
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

class BitcoinExchange {

private:
    static const char *_dbFileName;
    const char *_inputFileName;
    std::map<std::string, double> _inputContentMap;
    std::map<std::string, double> _dbContentMap;

    void storeContent(const char *fileName,
                                std::map<std::string, double> &map, char separator);
    bool isInputValid() const;
    bool isLineValid(std::string line);
    bool isFormatValid(std::string& input);
	bool isNumberValid(std::string& input);
    double getRate(std::string datePart) const;

public:
    BitcoinExchange();
    BitcoinExchange(char *infileName);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    
    void printRecords();
};
