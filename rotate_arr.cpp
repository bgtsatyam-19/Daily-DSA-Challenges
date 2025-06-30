#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // Handle if k > n

        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";  // ✅ Fixed: Added semicolon
    }
    cout << endl;

    return 0;
}
//time complexity O(n)
//space complexity O(1)