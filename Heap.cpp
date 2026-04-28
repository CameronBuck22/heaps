#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap(int cap) {
    capacity = cap;
    size = 0;
    arr = new int[capacity];
    isMaxHeap = true;
}

Heap::~Heap() {
    delete[] arr;
}

int Heap::parent(int i) {
    return (i - 1) / 2;
}

int Heap::leftChild(int i) {
    return 2 * i + 1;
}

int Heap::rightChild(int i) {
    return 2 * i + 2;
}

void Heap::heapifyUp(int index) {
    if (isMaxHeap) {
        while (index > 0 && arr[parent(index)] < arr[index]) {
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    } else {
        while (index > 0 && arr[parent(index)] > arr[index]) {
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }
}

// ✅ Task 1
void Heap::heapifyDown(int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapifyDown(largest);
    }
}

// helper for Task 5
void Heap::heapifyDownMin(int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyDownMin(smallest);
    }
}

void Heap::insert(int value) {
    if (size == capacity) return;

    arr[size] = value;
    heapifyUp(size);
    size++;
}

void Heap::deleteRoot() {
    if (size == 0) return;

    arr[0] = arr[size - 1];
    size--;

    if (isMaxHeap)
        heapifyDown(0);
    else
        heapifyDownMin(0);
}

// ✅ Task 2 (Floyd’s build)
void Heap::buildH(int input[], int n) {
    size = n;

    for (int i = 0; i < n; i++)
        arr[i] = input[i];

    for (int i = size / 2 - 1; i >= 0; i--)
        heapifyDown(i);

    isMaxHeap = true;
}

// ✅ Task 3
void Heap::replace(int oldValue, int newValue) {
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == oldValue) {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    arr[index] = newValue;

    if (isMaxHeap) {
        if (index > 0 && arr[index] > arr[parent(index)])
            heapifyUp(index);
        else
            heapifyDown(index);
    } else {
        if (index > 0 && arr[index] < arr[parent(index)])
            heapifyUp(index);
        else
            heapifyDownMin(index);
    }
}

// ✅ Task 4
void Heap::heapSort() {
    int originalSize = size;

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        size--;
        heapifyDown(0);
    }

    size = originalSize;
}

// ✅ Task 5
void Heap::switchMinMax() {
    if (isMaxHeap) {
        isMaxHeap = false;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyDownMin(i);
    } else {
        isMaxHeap = true;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }
}

void Heap::display() {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
