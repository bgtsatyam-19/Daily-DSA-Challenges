#include<bits/stdc++.h>
using namespace std;
class NumArray {
    vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix.resize(n+1,0);
        for(int i=0;i<n;++i){
            prefix[i+1]=prefix[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);

    cout << "sumRange(0, 2): " << obj->sumRange(0, 2) << endl;  // Expected: 1
    cout << "sumRange(2, 5): " << obj->sumRange(2, 5) << endl;  // Expected: -1
    cout << "sumRange(0, 5): " << obj->sumRange(0, 5) << endl;  // Expected: -3

    delete obj; // free memory
    return 0;
}