
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

void printStack(std::stack<char> s) {
    while (!s.empty()) {
        std::cout << s.top() << "-";
        s.pop();
    }
    std::cout << std::endl;
}

void RPN::calculateRPN(std::string str) {
    int result = 0;

    if (!isRPNValid(str)) {
        std::cout << "Error" << std::endl;
        return;
    }

    std::stringstream ss(str);  
    std::string tokenStr;
    char token;

    while (ss >> tokenStr) {
        token = tokenStr[0];
        std::cout << "token: " << token << std::endl;

        //printStack(_stack);
        if (std::isdigit(token)) {
            std::cout << "is digit" << std::endl;
            _stack.push(token);
        }
        else if (isOperator(token)) {
            int a = _stack.top() - '0';
            _stack.pop();
            int b = _stack.top() - '0';
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
            }
            _stack.push(result + '0');
        }
    }
    std::cout << result << std::endl;
}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isRPNValid(std::string str) {
    std::stringstream ss(str);  
    std::string token;

    while (ss >> token) { // Extract token from the stream.
        if (token.length() > 1 || (!std::isdigit(token[0])
                                    && !isOperator(token[0]))) {
            return false;
        }
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return true;
}
