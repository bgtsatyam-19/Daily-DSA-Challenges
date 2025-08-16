#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; 
        for(int i=0; i<nums.size(); i++){
            auto it = window.lower_bound((long long)nums[i] - valueDiff);
    
            if(it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }
            window.insert(nums[i]);
            if(window.size() > indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.containsNearbyAlmostDuplicate(nums, 3, 0); 
}



