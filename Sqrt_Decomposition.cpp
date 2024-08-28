#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SqrtDecomposition {
public:
    SqrtDecomposition(const vector<int>& input) {
        n = input.size();
        blockSize = ceil(sqrt(n));
        blocks = vector<int>((n + blockSize - 1) / blockSize, 0); // Initialize blocks

        // Fill blocks with initial values
        for (int i = 0; i < n; ++i) {
            arr.push_back(input[i]);
            blocks[i / blockSize] += input[i];
        }
    }

    void update(int index, int value) {
        int blockIndex = index / blockSize;
        blocks[blockIndex] += value - arr[index]; // Update block sum
        arr[index] = value;
    }

    int query(int left, int right) {
        int sum = 0;
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;

        if (startBlock == endBlock) { // If the range is within the same block
            for (int i = left; i <= right; ++i) {
                sum += arr[i];
            }
        } else {
            // Sum elements in the left part
            for (int i = left; i < (startBlock + 1) * blockSize; ++i) {
                sum += arr[i];
            }
            // Sum whole blocks in between
            for (int i = startBlock + 1; i < endBlock; ++i) {
                sum += blocks[i];
            }
            // Sum elements in the right part
            for (int i = endBlock * blockSize; i <= right; ++i) {
                sum += arr[i];
            }
        }
        return sum;
    }

private:
    vector<int> arr; // Original array
    vector<int> blocks; // Sqrt decomposition blocks
    int blockSize;
    int n;
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    SqrtDecomposition sqrtDec(input);

    cout << "Sum of range (0, 10): " << sqrtDec.query(0, 10) << endl;
    sqrtDec.update(4, 10);
    cout << "Sum of range (0, 10) after update: " << sqrtDec.query(0, 10) << endl;

    return 0;
}
