
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
        return;
    }
    while (std::getline(inFile, line)) {
        vector.push_back(line);
    }
    inFile.close();
}

bool BitcoinExchange::isInputValid() const {

    if (inputContent.empty()) {
        std::cout << "Error: Input file is empty or doesn't exist!" << std::endl;
        return false;
    }
    if (inputContent.at(0) != "date | value") {
        std::cout << "Error: Input file is not valid!" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isFormatValid(const std::string& line) const {
    std::string datePart;
    std::string valuePart;
    float value = 0;

    if (!(line.length() >= 14 && line[10] == ' ' && line[12] == ' ' && line[13] != ' ')) {
        std::cout << "Error: Invalid format => " << line << std::endl;
        return false;
    }

    datePart = line.substr(0, 10);
    valuePart = line.substr(13);

    if (datePart.length() != 10 || datePart[4] != '-' || datePart[7] != '-') {
        std::cout << "Error: Invalid date format => " << datePart << std::endl;
        return false;
    }

    std::istringstream strStream(valuePart);

    std::string valueStr;
    if (!(strStream >> valueStr)) {
        return false;
    }

    if (!strStream.eof()) {
        std::cout << "Error: Invalid value format (no eof in the end)!" << std::endl;
        return false;
    }

    std::istringstream valueStream(valueStr);
    if (!(valueStream >> value)) {
        std::cout << "Error: Invalid numerical value!" << std::endl;
        return false;
    }

    if (value < 0 || value > 1000) {
        std::cout << "Error: Number out of range => " << value << std::endl;
        return false;
    }
    std::string leftover;
    valueStream >> leftover;

    if (leftover != "f" && !leftover.empty()) {
        std::cout << "Error: Invalid value format! => " << leftover << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isDateValid(const std::string& line) const {
    std::string datePart = line.substr(0, 10);
    std::string monthPart;
    std::string dayPart;
    std::string::iterator it;

    for (it = datePart.begin(); it != datePart.end(); it++) {
        if (!isdigit(*it) && *it != '-') {
            std::cout << "Error: Invalid date format => " << datePart << std::endl;
            return false;
        }
    }
    monthPart = datePart.substr(5, 2);
    dayPart = datePart.substr(8, 2);

    if (monthPart < "01" || monthPart > "12") {
        std::cout << "Error: Invalid month format => " << monthPart << std::endl;
        return false;
    }

    if (dayPart < "01" || dayPart > "31") {
        std::cout << "Error: Invalid day format => " << dayPart << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isLineValid(std::string line) const {
    std::string::iterator it;

    if (line.empty()) {
        std::cout << "Error: Line is empty!" << std::endl;
        return false;
    }
    // check if line has format "YYYY-MM-DD | value"
    if (!isFormatValid(line)) {
        return false;
    }
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

double BitcoinExchange::getRate(std::string datePart) const {
    std::string dbDate;
    std::string dbValue;
    std::string dbRate;
    std::vector<std::string>::const_iterator it;
    double rate = 0.0;

    
    for (it = this->dbContent.begin(); it != this->dbContent.end(); it++) {
        std::string prev = *(it - 1);
        std::string curr = *it;

        dbDate = curr.substr(0, 10);
        dbValue = curr.substr(11, curr.length() - 11);
        dbRate = curr.substr(11, curr.length() - 11);

        if (dbDate == datePart) {
            rate = std::strtod(dbRate.c_str(), NULL);
            break;
        }
        else if (dbDate > datePart && it != this->dbContent.begin()) {
            dbRate = prev.substr(11, prev.length() - 11);
            rate = std::strtod(dbRate.c_str(), NULL);
            break;
        }
        else if (dbDate > datePart) {
            rate = std::strtod(dbRate.c_str(), NULL);
            break;
        }
    }
    return rate;
}

void BitcoinExchange::printRecords() const {
    std::vector<std::string>::const_iterator it;
    std::string datePart;

    if (!isInputValid()) {
        return;
    }
    if (inputContent.size() == 1) {
        std::cout << "Error: No records found!" << std::endl;
    }

    for (it = inputContent.begin() + 1; it != inputContent.end(); it++) {
        if (isLineValid(*it)) {
            datePart = it->substr(0, 10); 
            std::cout << datePart;
            std::cout << " => ";
            std::cout << (*it).substr(11, it->length() - 11);
            std::cout << " = " << getValue(*it) * getRate(datePart) << std::endl;
        }
    }
}

