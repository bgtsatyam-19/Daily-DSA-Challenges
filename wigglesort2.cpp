#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int mid = (n + 1) / 2;    
        int j = mid - 1;          
        int k = n - 1;            

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--]; 
            } else {
                nums[i] = sorted[k--];
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,5,1,1,6,4};
    s.wiggleSort(nums);

    for (int x : nums) cout << x << " ";
    return 0;
}
