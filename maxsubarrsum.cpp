#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> minPrefix(k, LLONG_MAX);
        long long ans = LLONG_MIN;
        minPrefix[0] = 0;

        for (int i = 1; i <= nums.size(); i++) {
            int r = i % k;
            if (minPrefix[r] != LLONG_MAX)
                ans = max(ans, prefix[i] - minPrefix[r]);
            minPrefix[r] = min(minPrefix[r], prefix[i]);
        }

        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> nums={2,-1,2,3,4,-5};
    int k=3;
    cout<<obj.maxSubarraySum(nums,k)<<endl; 
    return 0;
}
