#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        tmp[0] = 45;
        std::cout << "tmp: " << tmp[0] << std::endl;
        std::cout << "numbers: " << numbers[0] << std::endl;

        Array<int> test(tmp);
        test[0] = 35;
        tmp[0] = 40;
        std::cout << "test: " << test[0] << std::endl;
        std::cout << "tmp: " << tmp[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Successfully saved values" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": index out of bounds" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": index out of bounds" << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << std::endl;
    delete [] mirror;//
    return 0;
}