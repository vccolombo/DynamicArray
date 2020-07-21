#include <stdlib.h>
#include <string.h>

#include "DynamicArray.hpp"

DynamicArray::DynamicArray(int initialSize) {
    this->capacity = initialSize;
    this->array = (int*) malloc(this->capacity * sizeof(int));
}

DynamicArray::~DynamicArray() {
    free(this->array);
}

// O(N) runtime
void DynamicArray::doubleArray() {
    this->capacity *= 2;
    int *newArray = (int*) malloc(this->capacity * sizeof(int));
    memcpy(newArray, this->array, this->length * sizeof(int));
    this->array = newArray;
}

int DynamicArray::size() {
    return this->length;
}

// O(1) runtime
int DynamicArray::get(int index) {
    return this->array[index];
}

void DynamicArray::set(int index, int value) {
    this->array[index] = value;
}

// O(1) (amortized) runtime
void DynamicArray::append(int value) {
    if (this->length == this->capacity) {
        this->doubleArray();
    }

    this->array[this->length] = value;
    this->length++;
}

// O(N) runtime
void DynamicArray::insert(int index, int value) {
    if (this->length == this->capacity) {
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