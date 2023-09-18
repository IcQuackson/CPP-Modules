#include "../includes/MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "begin: " << *it << std::endl;
    std::cout << "end: " << *ite << std::endl;
    ++it;
    --it;

    while (it != ite)
    {
        // "it: 5", "it: 3", "it: 5", "it: 737", "it: 0"
        std::cout << "it: " << *it << std::endl; 
        ++it;
    }

    std::stack<int> s(mstack);
    return 0;
}