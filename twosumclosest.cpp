#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2]; // initial guess

        for(int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                // If exact match found
                if(current_sum == target)
                    return current_sum;

                // Update closest if needed
                if(abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }

                // Move pointers based on comparison
                if(current_sum < target)
                    ++left;
                else
                    --right;
            }
        }

        return closest_sum;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;
}