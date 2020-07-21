#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#define INIT_SIZE 10

class DynamicArray {
    int *array;
    int length = 0;
    int capacity;

    void doubleArray();

    public:
        DynamicArray(int initialSize = INIT_SIZE);
        ~DynamicArray();
        int size();
        int get(int index);
        void set(int index, int value);
        void append(int value);
        void insert(int index, int value);
        void remove(int index);
        bool contains(int value);
};

#endif