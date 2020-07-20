#include <stdlib.h>
#include <string.h>

#include "DynamicArray.hpp"

DynamicArray::DynamicArray(int initialSize) {
    this->maxLength = initialSize;
    this->array = (int*) malloc(this->maxLength * sizeof(int));
}

// O(N) runtime
void DynamicArray::doubleArray() {
    this->maxLength *= 2;
    int *newArray = (int*) malloc(this->maxLength * sizeof(int));
    memcpy(newArray, this->array, this->length * sizeof(int));
    this->array = newArray;
}

int DynamicArray::getLength() {
    return this->length;
}

// O(1) runtime
int DynamicArray::get(int index) {
    return this->array[index];
}

// O(1) (amortized) runtime
void DynamicArray::append(int value) {
    if (this->length == this->maxLength) {
        this->doubleArray();
    }

    this->array[this->length] = value;
    this->length++;
}

// O(N) runtime
void DynamicArray::insert(int value, int index) {
    if (this->length == this->maxLength) {
        this->doubleArray();
    }

    for (size_t i = this->length - 1; i >= index; i--) {
        this->array[i + 1] = this->array[i];
    }

    this->array[index] = value;
    this->length++;
}

// O(N) runtime
void DynamicArray::remove(int index) {
    for (size_t i = index; i < this->length - 1; i++) {
        this->array[i] = this->array[i + 1];
    }
}