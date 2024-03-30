#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
    MaxHeap() {}

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty" << std::endl;
            return -1; 
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

private:
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
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
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(4);
    maxHeap.insert(2);
    maxHeap.insert(8);
    maxHeap.insert(1);

    cout << "Max element extracted: " << maxHeap.extractMax() << endl;
    cout << "Max element extracted: " << maxHeap.extractMax() << endl;

    return 0;
}
