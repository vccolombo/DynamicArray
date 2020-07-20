#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define INIT_SIZE 10

class DynamicArray {
    int *array;
    int length = 0;
    int maxLength;

    void doubleArray();

    public:
        DynamicArray(int initialSize = INIT_SIZE);
        int getLength();
        int get(int index);
        void append(int value);
        void insert(int value, int index);
        void remove(int index);
};

#endif