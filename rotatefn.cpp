//Rotate Function
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        long long F = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            F += i * nums[i];
        }

        long long maxF = F;
        for (int k = 1; k < n; ++k) {
            F = F + totalSum - (long long)n * nums[n - k];
            maxF = max(maxF, F);
        }

        return static_cast<int>(maxF);
    }
};
int main(){
    Solution obj;
    vector<int> nums={4,3,2,6};
    cout<<obj.maxRotateFunction(nums)<<endl; //Output: 26
    return 0;
}