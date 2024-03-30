#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    MinHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1; 
        }

        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

private:
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }

            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(1);

    cout << "Min element extracted: " << minHeap.extractMin() << endl;
    cout << "Min element extracted: " << minHeap.extractMin() << endl;

    return 0;
}
