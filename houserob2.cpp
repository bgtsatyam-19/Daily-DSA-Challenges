#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }

    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
   
    }
};int main(){
    Solution obj;
    vector<int> nums = {1,2,3,1};
    cout<<obj.rob(nums)<<endl;
    return 0;
}