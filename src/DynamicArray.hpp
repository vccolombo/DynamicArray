#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 10

template <typename T>
class DynamicArray {
    T* array;
    int length = 0;
    int capacity;

    void doubleArray();

    public:
        DynamicArray(int initialSize = INIT_SIZE);
        ~DynamicArray();
        int size();
        T &operator[](int index);
        T get(int index);
        void set(int index, T value);
        void append(T value);
        void insert(int index, T value);
        void remove(int index);
        bool contains(T value);
};

// Implementation must be inside hpp for generics to work
// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

template <typename T>
DynamicArray<T>::DynamicArray(int initialSize) {
    this->capacity = initialSize;
    this->array = new T[initialSize];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->array;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::doubleArray() {
    this->capacity *= 2;
    T* newArray = new T[this->capacity];
    memcpy(newArray, this->array, this->length * sizeof(T));
    
    T* temp = this->array;
    this->array = newArray;
    delete[] temp;
}

template <typename T>
int DynamicArray<T>::size() {
    return this->length;
}

// O(1) runtime
template <typename T>
T &DynamicArray<T>::operator[](int index) {
    return this->array[index];
}

// O(1) runtime
template <typename T>
T DynamicArray<T>::get(int index) {
    return this->array[index];
}

// O(1) runtime
template <typename T>
void DynamicArray<T>::set(int index, T value) {
    this->array[index] = value;
}

// O(1) (amortized) runtime
template <typename T>
void DynamicArray<T>::append(T value) {
    if (this->length == this->capacity) {
        this->doubleArray();
    }

    this->array[this->length] = value;
    this->length++;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::insert(int index, T value) {
    if (this->length == this->capacity) {
        this->doubleArray();
    }

    for (size_t i = this->length-1; i >= index; i--) {
        this->array[i+1] = this->array[i];
    }

    this->array[index] = value;
    this->length++;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::remove(int index) {
    for (size_t i = index; i < this->length-1; i++) {
        this->array[i] = this->array[i+1];
    }

    this->length--;
}

// O(N) runtime
template <typename T>
bool DynamicArray<T>::contains(T value) {
    for (size_t i = 0; i < this->length; i++) {
        if (this->array[i] == value) return true;
    }
    
    return false;
}

#endif