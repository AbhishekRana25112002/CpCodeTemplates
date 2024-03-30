#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
public:
    vector<int> nums;
    vector<int> segment_tree;
    // Constructor   
    SegmentTree(vector<int> &arr){
        nums = arr;
        int n = arr.size();
        int segmentSize = 4 * n;           // The simplest segment size if 4n
        segment_tree.resize(segmentSize, 0);
        buildTree(0, n-1, 0);
    }
    void buildTree(int sl, int sr, int i){
        if(sl == sr){
            segment_tree[i] = nums[sl];
            return;
        }
        int mid = sl + (sr-sl)/2;
        buildTree(sl, mid, 2*i+1);
        buildTree(mid+1, sr, 2*i+2);
        segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
        return;
    }
    void update_utils(int sl, int sr, int curI, int index, int key, int changeValue){
        if(sl == sr){
            segment_tree[curI] = key;
            return;
        }
        segment_tree[curI] += changeValue;
        int mid = sl + (sr - sl)/2;
        if(index <= mid )
            update_utils(sl, mid, 2*curI+1, index, key, changeValue);
        else
            update_utils(mid+1, sr, 2*curI+2, index, key, changeValue);
    }
    
    void update(int n, int index, int key){
        int changeValue = key - nums[index];
        nums[index] = key;
        update_utils(0, n-1, 0, index, key, changeValue);
    }
    
    int calculateSum(int sl, int sr, int index, int ql, int qr){
        if(sr < ql || sl > qr)              return 0;
        if(sl >= ql && sr <= qr)            return segment_tree[index];
        int mid = sl + (sr-sl)/2;
        return calculateSum(sl, mid, 2*index+1, ql, qr)+
            calculateSum(mid+1, sr, 2*index+2, ql, qr);
    }
};
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 1, 3, 5};
    SegmentTree st = SegmentTree(arr);
    st.update(arr.size(), 2, 4);
    cout << st.calculateSum(0, arr.size() - 1, 0, 6, 8) << endl;
}