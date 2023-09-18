
#include "BitcoinExchange.hpp"

const char *BitcoinExchange::dbFileName = "data.csv";

BitcoinExchange::BitcoinExchange() {
    this->inputContent = std::vector<std::string>();
    this->dbContent = std::vector<std::string>();
}

BitcoinExchange::BitcoinExchange(char *infileName) {
    this->storeContent(infileName, this->inputContent);
    this->storeContent(dbFileName, this->dbContent);
    this->dbContent.erase(this->dbContent.begin());
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->inputContent = other.inputContent;
        this->dbContent = other.dbContent;
    }
    return *this;
}

void BitcoinExchange::storeContent(const char *fileName, std::vector<std::string> &vector) {
    std::string line;
    std::ifstream inFile(fileName);

    if (!inFile) {
        std::cout << "File: " << fileName << " does not exist!" << std::endl;
        return;
    }
    while (std::getline(inFile, line)) {
        vector.push_back(line);
    }
    inFile.close();
}

bool BitcoinExchange::isInputValid() const {

    if (inputContent.empty()) {
        std::cout << "Input file is empty!" << std::endl;
        return false;
    }
    if (inputContent.at(0) != "date | value") {
        std::cout << "Input file is not valid!" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isFormatValid(const std::string& line) const {
    std::string datePart;
    std::string valuePart;

    if (!(line.length() >= 14 && line[10] == ' ' && line[12] == ' ')) {
        std::cout << "Invalid format!" << std::endl;
        return false;
    }

    datePart = line.substr(0, 10);
    valuePart = line.substr(13);

    if (datePart.length() != 10 || datePart[4] != '-' || datePart[7] != '-') {
        std::cout << "Invalid date format!" << std::endl;
        return false;
    }

    std::istringstream valueStream(valuePart);
    int intValue;
    float floatValue;
    double doubleValue;

    if (!(valueStream >> intValue || valueStream >> floatValue || valueStream >> doubleValue)) {
        std::cout << "Error: Not a valid numerical value!" << std::endl;
        return false;
    }

    if (intValue < 0 || floatValue < 0 || doubleValue < 0
     || intValue > 1000 || floatValue > 1000 || doubleValue > 1000) {
        std::cout << "Error: value out of range!" << std::endl;
        return false;
    }

    if (!valueStream.eof()) {
        std::cout << "Invalid value format!" << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isDateValid(const std::string& line) const {
    std::string datePart = line.substr(0, 10);
    std::string::iterator it;

    for (it = datePart.begin(); it != datePart.end(); it++) {
        if (!isdigit(*it) && *it != '-') {
            std::cout << "Invalid date format!" << std::endl;
            return false;
        }
    }
    if (datePart.substr(5, 7) < "01" || datePart.substr(5, 7) > "12") {
        std::cout << "Invalid date format!" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isLineValid(std::string line) const {
    std::string::iterator it;

    if (line.empty()) {
        std::cout << "Line is empty!" << std::endl;
        return false;
    }
    // check if line has format "YYYY-MM-DD | value"
    if (!isFormatValid(line)) {
        return false;
    }
    // check if date is valid
    if (!isDateValid(line)) {
        return false;
    }
    return true;
}

double BitcoinExchange::getValue(const std::string& line) const {
    std::string valuePart = line.substr(13);
    std::istringstream valueStream(valuePart);
    double value;

    valueStream >> value;
    return value;
}

double BitcoinExchange::getRate(const std::string& line) const {
    std::string datePart = line.substr(0, 10);
    std::string::iterator it;
    std::string dbDate;
    std::string dbValue;
    std::string dbRate;
    double rate;

    
    for (it = this->dbContent.begin(); it != this->dbContent.end(); it++) {
        dbDate = *it.substr(0, 10);
        dbValue = (*it).substr(11, (*it).length() - 11);
        dbRate = (*it).substr(11, (*it).length() - 11);
        if (dbDate == datePart) {
            rate = std::stod(dbRate, NULL);
            break;
        }
        else if (dbDate > datePart && it != this->dbContent.begin()) {
            dbRate = (*(it - 1)).substr(11, *(it - 1).length() - 11);
            rate = std::stod(dbRate, NULL);
            break;
        }
        else if (dbDate > datePart) {
            rate = std::stod(dbRate, NULL);
            break;
        }
    }
    return rate;
}

void BitcoinExchange::printRecords() const {
    std::vector<std::string>::const_iterator it;

    if (!isInputValid()) {
        return;
    }

    for (it = inputContent.begin() + 1; it != inputContent.end(); it++) {
        if (isLineValid(*it)) {
            std::cout << (*it).substr(0, 10);
            std::cout << " => ";
            std::cout << (*it).substr(11, it->length() - 11);
            std::cout << " = " << getValue(*it) * getRate(*it)  << std::endl;
        }
    }
}

