
#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN::~RPN() {
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other) {
    }
    return *this;
}

void RPN::calculateRPN(std::string str) {
    int token;

    if (!isRPNValid(str)) {
        std::cout << "Error" << std::endl;
        return;
    } 

    for (size_t i = 0; i < str.size(); i++) {
		token = str[i];
		if (std::isspace(token)) {
			continue;
		}
		if (std::isdigit(token)) {
			_stack.push(token - '0');
		}
        else {
            int b, a;
			int result;
			
			b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();
            result = 0;

            if (token == '+') {
                result = a + b;
            } else if (token == '-') {	
                result = a - b;
            } else if (token == '*') {
                result = a * b;
            } else if (token == '/') {
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

bool RPN::isOperator(int token) {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

bool RPN::isRPNValid(std::string str) {
    std::stringstream ss(str);  
    std::string token;

    while (ss >> token) { // Extract token from the stream.
        if (token.length() > 1 || (!std::isdigit(token[0])
                                    && !isOperator(token[0]))) {
            return false;
        }
    }
    return true;
}
