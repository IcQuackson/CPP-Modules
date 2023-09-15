
#pragma once

#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*function)(T&)) {
    for (int i = 0; i < len; i++) {
        function(arr[i]);
    }
}

template <typename T>
void testPrint(T &a) {
    std::cout << a << std::endl;
}
