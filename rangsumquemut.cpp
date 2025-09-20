#include<bits/stdc++.h>
using namespace std;
class NumArray {
    vector<int> bit;
    vector<int> arr; 
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }
    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void update(int index, int val) {
        int diff = val - arr[index]; 
        arr[index] = val; 
        add(index + 1, diff);
    }

    int prefixSum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};
int main() {
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl; // Output: 9
    obj->update(1, 2);
    cout << obj->sumRange(0, 2) << endl; // Output: 8
    return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */