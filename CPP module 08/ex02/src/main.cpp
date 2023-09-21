#include "../includes/MutantStack.hpp"

int main()
{
	{
		std::cout << "MUTANT STACK" << std::endl << std::endl;
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

		std::cout << std::endl;
		while (it != ite)
		{
			// 5, 3, 5, 737, 0
			std::cout << "it: " << *it << std::endl; 
			++it;
		}
		std::cout << std::endl;

		std::stack<int> s(mstack);
		std::cout << "top: " << s.top() << std::endl;
		std::cout << "size: " << s.size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "LIST" << std::endl << std::endl;
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "top: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size: " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		std::cout << "begin: " << *it << std::endl;
		std::cout << "end: " << *ite << std::endl;
		++it;
		--it;

		std::cout << std::endl;
		while (it != ite)
		{
			// 5, 3, 5, 737, 0
			std::cout << "it: " << *it << std::endl; 
			++it;
		}
		//std::stack<int> s(mstack);
	}

    return 0;
}