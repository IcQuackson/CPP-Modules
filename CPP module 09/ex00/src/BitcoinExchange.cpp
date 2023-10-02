#include "BitcoinExchange.hpp"

const char *BitcoinExchange::_dbFileName = "data.csv";

BitcoinExchange::BitcoinExchange() {
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

bool BitcoinExchange::isNumberValid(std::string& input) {
	if (input.empty() || input.find_first_not_of("f0123456789.") != std::string::npos) {
		return false;
	}

    std::istringstream iss(input);
    float value;

    // Try to extract a float from the string
    iss >> value;

	if (iss.fail()) {
		return false;
    }

    if (!iss.eof()) {
        std::string remaining;
        iss >> remaining;

        // Check if the remaining string is "f"
        if (remaining != "f") {
            return false;
        }
    }
	
    return value > 0 && value < 1000.0;
}

bool BitcoinExchange::isFormatValid(std::string& input) {
    // Define the format "year-MM-DD "
    const char* dateFormat = "%Y-%m-%d ";
	int spaces = 0;
    
    // Find the position of the | character
    size_t separatorPos = input.find('|');

    if (separatorPos != std::string::npos) {
        // Extract the substring before the | character (date part)
        std::string datePart = input.substr(0, separatorPos);

        // Create a tm struct to store the parsed date
        std::tm tm;
		spaces = std::count(datePart.begin(), datePart.end(), ' ');

        if (spaces == 1 && strptime(datePart.c_str(), dateFormat, &tm) != NULL) {

			// Check if month and day are valid
			size_t monthAndDayPos = datePart.find("-") + 1;
			std::string monthAndDay = datePart.substr(monthAndDayPos);

			if (monthAndDay.length() != 6) {
				std::cout << "Error: date format is not valid: " << input << std::endl;
				return false;
			}

            // Check if there is exactly one space after the date
            if (separatorPos + 1 < input.size() && input[separatorPos + 1] == ' ') {
                // Extract the substring after the | character (number part)
                std::string numberPart = input.substr(separatorPos + 2);

                // Check if the number part is a valid number
				if (isNumberValid(numberPart)) {
					return true;
				}
				else {
					std::cout << "Error: number is not valid: " << numberPart << std::endl;
					return false;
				}
            }
			else {
				std::cout << "Error: line format is not valid!: " << input << std::endl;
                return false;
			}
        }
    }
	std::cout << "Error: date format is not valid: " << input << std::endl;
    return false;
}

bool BitcoinExchange::isLineValid(std::string line) {
    std::string::iterator it;
    //std::string date;

    if (line.empty()) {
        std::cout << "Error: Line is empty!" << std::endl;
        return false;
    }
    // check if line has format "YYYY-MM-DD | value"
    if (!isFormatValid(line)) {
        return false;
    }
    
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
    std::string date;
	float value;

    if (!isInputValid()) {
        return;
    }
    
    std::ifstream inputFile(_inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file!" << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line); // ignore the header line

	int i = 0;
    while (getline(inputFile, line)) {
        if (isLineValid(line)) {
			date = line.substr(0, line.find("|"));
            value = std::strtod(line.substr(line.find("|") + 2).c_str(), NULL);
            std::cout << date << " => ";
            std::cout << value << " = " << value * getRate(date) << std::endl;
        }
		i++;
    }
	inputFile.close();
	if (i == 0) {
		std::cout << "Error: No records found!" << std::endl;
	}
}
