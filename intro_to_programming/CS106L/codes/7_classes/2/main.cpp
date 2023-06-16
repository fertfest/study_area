#include "DynamicArray.h"
#include <iostream>

// Gave you the main from the solution but feel free to change!
int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    DynamicArray arr(size);
    arr.setSquaredIndices();
    arr.displayElements();

    return 0;
}

