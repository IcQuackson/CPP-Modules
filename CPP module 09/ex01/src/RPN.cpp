
#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN::~RPN() {
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

void RPN::calculateRPN(std::string str) {
    std::string token;
    std::istringstream iss(str);

    if (!isRPNValid(str)) {
        std::cout << "Error" << std::endl;
        return;
    } 

    while (iss >> token) {
		if (!isOperator(token)) {
			_stack.push(std::atoi(token.c_str()));
		}
        else {
            int b, a;
			int result;
			
			if (_stack.size() < 2) {
                std::cout << "Error" << std::endl;
                return;
            }
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();
            result = 0;

            if (token == "+") {
                result = a + b;
            } else if (token == "-") {	
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                if (b == 0) {
                    std::cout << "Error: Division by Zero" << std::endl;
                    return;
                }
                result = a / b;
            } else {
				std::cout << "Error" << std::endl;
				return;
			}
            _stack.push(result);
        }
    }
	if (_stack.size() == 1) {
    	std::cout << _stack.top() << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}
}

bool RPN::isOperator(std::string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isValidNumber(std::string &str) {
    if (str.length() > 2 || str.empty()) {
        return false;
    }
    if (str.length() == 1 && !std::isdigit(str[0])) {
        return false;
    }
    if (str.length() == 2 && str[0] != '-' && str[0] != '+') {
        return false;
    }
    if (str.length() == 2 && !std::isdigit(str[1])) {
        return false;
    }
    return true;
}

bool RPN::isRPNValid(std::string str) {
    std::stringstream ss(str);  
    std::string token;

    while (ss >> token) { // Extract token from the stream.
        if (!isValidNumber(token) && !isOperator(token)) {
            return false;
        }
    }
    return true;
}
