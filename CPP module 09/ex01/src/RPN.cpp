
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

    if (!isRPNValid(str)) {
        std::cout << "Error" << std::endl;
        return;
    }

    std::istream ss(str);  
    int token;

    while (ss >> token) {
        std::cout << "token: " << token << std::endl;

        if (isOperator(token)) {
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            int result = 0;
            if (token == '+') {
                result = a + b;
            } else if (token == '-') {
                result = a - b;
            } else if (token == '*') {
                result = a * b;
            } else if (token == '/') {
                result = a / b;
            }
            _stack.push(std::to_string(result));
        }
        else {
            _stack.push(token);
        }
    }
    printStack(_stack);
    std::cout << _stack.top() << std::endl;
}

bool RPN::isOperator(std::string str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool RPN::isRPNValid(std::string str) {
    std::stringstream ss(str);  
    std::string token;

    while (ss >> token) { // Extract token from the stream.
        if (token.length() > 1 || (!std::isdigit(token[0])
                                    && !isOperator(token))) {
            return false;
        }
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return true;
}
