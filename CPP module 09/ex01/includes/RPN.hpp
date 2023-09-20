#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {

private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(RPN const &other);
    ~RPN();
    RPN &operator=(RPN const &other);

    void calculateRPN(std::string str);
    bool isOperator(std::string str);
    bool isRPNValid(std::string str);
};