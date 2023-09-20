#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN {

private:
    std::stack<char> _stack;

public:
    RPN();
    RPN(RPN const &other);
    ~RPN();
    RPN &operator=(RPN const &other);

    void calculateRPN(std::string str);
    bool isOperator(char c);
    bool isRPNValid(std::string str);
};