#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
    int* arr;
    int capacity;
    int size;
    bool isMaxHeap;

    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);

    void heapifyUp(int index);
    void heapifyDown(int index);
    void heapifyDownMin(int index);

public:
    Heap(int cap);
    ~Heap();

    void insert(int value);
    void deleteRoot();

    void buildH(int input[], int n);     // Task 2
    void replace(int oldValue, int newValue); // Task 3
    void heapSort();                    // Task 4
    void switchMinMax();                // Task 5

    void display();
};

#endif
