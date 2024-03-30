class sqrtDecomposition {
    private:
        int blockSize;
        vector<int> values, blocks;

    public:
        // preprocessing the input, calculating sum of blocks
        sqrtDecomposition(vector<int>& input) {
            int n = input.size();
            blockSize = ceil(sqrt(n));
            int blockIndex = -1;

            values.resize(n);
            blocks.resize(blockSize);

            for(int i = 0; i < n; ++i) {
                values[i] = input[i];

                // storing sum of each block of size sqrt(n)
                if(i % blockSize == 0) blockIndex++;
                blocks[blockIndex] += input[i];
            }
        }

        // update - O(1) time
        void pointUpdate(int k, int newValue) {
            // finding block number of element to update
            int block = k / blockSize;
            blocks[block] += newValue - values[k]; // updated sum of block
            values[k] = newValue;
        }

        // query - O(sqrt(n)) time
        int rangeSumQuery(int left, int right) {
            int sum = 0;

            // calculating sum of leftmost block, it will handle the case of end points too
            while (left < right and (left % blockSize != 0) and left != 0) {
                sum += values[left];
                left++;
            }

            // calculating sum of all complete blocks
            while (left + blockSize - 1 <= right) {
                sum += blocks[left / blockSize];
                left += blockSize; // traversing whole block at once
            }

            // calculating sum of righttmost block
            while (left <= right) {
                sum += values[left];
                left++;
            }

            return sum;
        }
};

// driver code
int main() {
    vector<int> input = {3, 2, 4, 5, 1, 1, 5, 3, 7};
    sqrtDecomposition obj(input);
    cout << obj.rangeSumQuery(0, 2) << '\n'; // output = 3+2+4 = 9
    obj.pointUpdate(1, 6); // input[1] = 6
    cout << obj.rangeSumQuery(0, 2); // output = 3+6+4 = 13
}