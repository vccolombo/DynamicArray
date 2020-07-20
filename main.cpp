#include <stdio.h>

#include "src/DynamicArray.hpp"

int main() {
    DynamicArray array;
    for (size_t i = 0; i < 10; i++) {
        array.append(i);
    }
    for (size_t i = 1; i < array.getLength(); i+=3) {
        array.insert(i * 100, i);
    }
    array.remove(0);
    for (size_t i = 0; i < array.getLength(); i++) {
        printf("%d\n", array.get(i));
    }
}