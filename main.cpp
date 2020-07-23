#include <stdio.h>

#include "src/DynamicArray.hpp"

int main() {
    DynamicArray array;
    for (size_t i = 0; i < 10; i++) {
        array.append(i);
    }
    for (size_t i = 1; i < array.size(); i+=3) {
        array.insert(i, i * 100);
    }
    array.remove(0);
    array[4] = 123;
    for (size_t i = 0; i < array.size(); i++) {
        printf("%d\n", array[i]);
    }
}