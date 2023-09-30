#include "BitcoinExchange.hpp"

const char *BitcoinExchange::_dbFileName = "data.csv";

BitcoinExchange::BitcoinExchange() {
    _inputContentMap = std::map<std::string, double>();
    _dbContentMap = std::map<std::string, double>();
}

BitcoinExchange::BitcoinExchange(char * infileName) {
    this->storeContent("data.csv", _dbContentMap, ',');
    _inputFileName = infileName;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _inputContentMap = other._inputContentMap;
        _dbContentMap = other._dbContentMap;
    }
    return *this;
}

void BitcoinExchange::storeContent(const char *filename, std::map<std::string, double> &map, char separator) {
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line); // ignore the header columns

        while (std::getline(inputFile, line)) {
            std::istringstream lineStream(line);
            std::string date, valueStr;

            // Check if the line has exactly one occurrence of the separator
            std::getline(lineStream, date, separator);
            std::getline(lineStream, valueStr);

            // Convert the value string to double
            double value = std::strtod(valueStr.c_str(), NULL);

            // Add date-value pair to the map
            map[date] = value;
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open file." << std::endl;
    }
}

bool BitcoinExchange::isInputValid() const {
    std::ifstream inputFile(_inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file!" << std::endl;
        return false;
    }

    // Check if the file is empty
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: Input file is empty!" << std::endl;
        inputFile.close();
        return false;
    }

    // Check the header
    std::string header;
    std::getline(inputFile, header);

    if (header != "date | value") {
        std::cout << "Error: Input file header is not valid!" << std::endl;
        inputFile.close();
        return false;
    }

    // Check each line
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            std::cout << "Error: Line is empty!" << std::endl;
            inputFile.close();
            return false;
        }
    }

    inputFile.close();
    return true;
}

bool BitcoinExchange::isFormatValid(std::string& input) {
    // Define the format "year-MM-DD "
    const char* dateFormat = "%F ";
    
    // Find the position of the | character
    size_t separatorPos = input.find('|');

    if (separatorPos != std::string::npos) {
        // Extract the substring before the | character (date part)
        std::string datePart = input.substr(0, separatorPos);

        // Create a tm struct to store the parsed date
        std::tm tm;

        // Try to parse the datePart using the specified format
        if (strptime(datePart.c_str(), dateFormat, &tm) != NULL) {
            // Check if there is exactly one space after the date
            if (separatorPos + 1 < input.size() && input[separatorPos + 1] == ' ') {
                // Extract the substring after the | character (number part)
                std::string numberPart = input.substr(separatorPos + 2);

                // Check if the number is a valid integer or float between 0 and 1000
                std::istringstream numberStream(numberPart);
                float number;
                numberStream >> std::noskipws >> number; // Attempt to read a number

                // Check if the read was successful and the number is a valid float or integer
                if (!numberStream.fail() && number >= 0.0 && number <= 1000.0 && static_cast<int>(number) == number) {
                    // Everything is valid
                    return true;
                }
            }
        }
    }
    std::cout << "Error: Input format is not valid!" << std::endl;
    return false;
}

/* bool BitcoinExchange::isDateValid(const std::string line) const {
    // Define the format "year-MM-DD "
    const char* format = "%Y-%m-%d ";

    // Create a tm struct to store the parsed date
    std::tm tm = {};

    // Try to parse the input string using the specified format
    if (strptime(line.c_str(), format, &tm) != NULL) {
        // Check if there is exactly one space at the end
        size_t lastPos = line.find_last_not_of(" ");
        return (lastPos != std::string::npos)
            && (line.size() - 1) == ++lastPos
            && (line[lastPos] == ' ');
    }
    return false;
} */

bool BitcoinExchange::isLineValid(std::string line) {
    std::string::iterator it;
    //std::string date;

    if (line.empty()) {
        std::cout << "Error: Line is empty!" << std::endl;
        return false;
    }
    // check if line has format "YYYY-MM-DD | value"
    if (!isFormatValid(line)) {
        std::cout << "Error: Invalid line format => " << line << std::endl;
        return false;
    }
    
/*     date = line.substr(0, line.find("|"));
    if (!isDateValid(date)) {
        std::cout << "Error: Invalid date format => " << date << std::endl;
        return false;
    } */
    return true;
}

double BitcoinExchange::getRate(std::string datePart) const {
    double rate = 0.0;

    if (!_dbContentMap.empty()) {
        // Use iterator to access the first element
        std::map<std::string, double>::const_iterator it = _dbContentMap.begin();
        double firstRate = it->second;

        // If the requested date is before or equal to the first date in the map
        if (it->first >= datePart) {
            rate = firstRate;
        }
        else {
            // Iterate through the map to find the rate corresponding to the requested date
            for (; it != _dbContentMap.end(); ++it) {
                if (it->first > datePart) {
                    break;
                } else if (it->first == datePart) {
                    rate = it->second;
                    break;
                }
                rate = it->second; // Update rate for the current date
            }
        }
    }
    return rate;
}


void BitcoinExchange::printRecords() {
    std::map<std::string, double>::const_iterator it;
    std::string datePart;

    if (!isInputValid()) {
        return;
    }
    
    this->storeContent(_inputFileName, _inputContentMap, '|');

/*     std::cout << "All elements in the map:" << std::endl;
    for (std::map<std::string, double>::iterator it = _inputContentMap.begin(); it != _inputContentMap.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    } */

    if (_inputContentMap.empty()) {
        std::cout << "Error: No records found!" << std::endl;
        return;
    }

    std::ifstream inputFile(_inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file!" << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line); // ignore the header line

    for (it = _inputContentMap.begin(); it != _inputContentMap.end(); ++it) {
        std::getline(inputFile, line);
        if (isLineValid(line)) {
            datePart = it->first; // date is the key
            double value = it->second;

            std::cout << datePart << " => ";
            std::cout << value << " = " << value * getRate(datePart) << std::endl;
        }
    }
}


