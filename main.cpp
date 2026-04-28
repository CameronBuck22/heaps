#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
    Heap h(20);

    int values[] = {10, 40, 30, 60, 90, 70, 20};
    int n = 7;

    h.buildH(values, n);

    cout << "Max Heap: ";
    h.display();

    h.deleteRoot();
    cout << "After deleting root: ";
    h.display();

    h.replace(40, 100);
    cout << "After replace: ";
    h.display();

    h.heapSort();
    cout << "After heap sort: ";
    h.display();

    h.switchMinMax();
    cout << "Min Heap: ";
    h.display();

    return 0;
}
