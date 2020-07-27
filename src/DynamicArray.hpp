#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdlib.h>
#include <string.h>

template <typename T>
class DynamicArray {

    static const int MIN_CAPACITY;

    T* array;
    int mSize = 0;
    int mCapacity;

    void createArray(int size);
    void doubleArray();
    void shrinkArray();

    public:
        DynamicArray(int initialSize = MIN_CAPACITY);
        ~DynamicArray();
        int size();
        int capacity();
        bool isEmpty();
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
const int DynamicArray<T>::MIN_CAPACITY = 10;

template <typename T>
DynamicArray<T>::DynamicArray(int initialSize) {
    if (initialSize <= 0) {
        initialSize = MIN_CAPACITY;
    }

    this->mCapacity = initialSize;
    this->array = new T[initialSize];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->array;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::createArray(int size) {
    if (this->mCapacity < MIN_CAPACITY) {
        this->mCapacity = MIN_CAPACITY;
    }

    T* newArray = new T[size];
    memcpy(newArray, this->array, this->mSize * sizeof(T));

    T* temp = this->array;
    this->array = newArray;
    delete[] temp;
}

template <typename T>
void DynamicArray<T>::doubleArray() {
    this->mCapacity *= 2;
    this->createArray(this->mCapacity);
}

template <typename T>
void DynamicArray<T>::shrinkArray() {
    this->mCapacity /= 2;
    this->createArray(this->mCapacity);
}

// O(1) runtime
template <typename T>
int DynamicArray<T>::size() {
    return this->mSize;
}

// O(1) runtime
template <typename T>
int DynamicArray<T>::capacity() {
    return this->mCapacity;
}

// O(1) runtime
template <typename T>
bool DynamicArray<T>::isEmpty() {
    return this->mSize == 0;
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
    if (this->mSize == this->mCapacity) {
        this->doubleArray();
    }

    this->array[this->mSize] = value;
    this->mSize++;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::insert(int index, T value) {
    if (this->mSize == this->mCapacity) {
        this->doubleArray();
    }

    for (size_t i = this->mSize-1; i >= index; i--) {
        this->array[i+1] = this->array[i];
    }

    this->array[index] = value;
    this->mSize++;
}

// O(N) runtime
template <typename T>
void DynamicArray<T>::remove(int index) {
    for (size_t i = index; i < this->mSize-1; i++) {
        this->array[i] = this->array[i+1];
    }

    this->mSize--;

    // It should cut in half only when it is 3 times smaller than the capacity
    // to avoid a situation where removing and inserting a lot of times in sequence
    // Will cause multiple doubles and shrinks. 
    if (this->mCapacity > MIN_CAPACITY && this->mSize < this->mCapacity / 3) {
        this->shrinkArray();
    }
}

// O(N) runtime
template <typename T>
bool DynamicArray<T>::contains(T value) {
    for (size_t i = 0; i < this->mSize; i++) {
        if (this->array[i] == value) return true;
    }
    
    return false;
}

#endif