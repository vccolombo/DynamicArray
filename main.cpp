#include <iostream>
#include <string>

#include "src/DynamicArray.hpp"

void intArrayExample() {
    DynamicArray<int> array;
    for (size_t i = 0; i < 10000; i++) {
        array.append(i);
    }
    for (size_t i = 1; i < array.size(); i+=3) {
        array.insert(i, i * 100);
    }
    array.remove(0);
    array[4] = 123;
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}

void stringArrayExample() {
    DynamicArray<std::string> array;
    array.append("Hello");
    array.append("World!");
    array.append("My");
    array.append("nose");
    array.append("is");
    array.append("perfect.");
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}

void clearArrayExample() {
    DynamicArray<int> array(42);
    for (size_t i = 0; i < 1331; i++) {
        array.append(i);
    }

    while (!array.isEmpty()) {
        std::cout << "Removing element with value " << array[0] << "\n";
        array.remove(0);
        std::cout << "Size: " << array.size() << " Capacity: " << array.capacity() << "\n";
    }

    std::cout << "\n";
}

int main() {
    intArrayExample();
    stringArrayExample();
    clearArrayExample();
}