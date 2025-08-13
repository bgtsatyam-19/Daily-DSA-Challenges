//Minimum Size Subarray Sum 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum =0;
        int minlen =INT_MAX;
        while(right<n){
            sum +=nums[right];
            while(sum >= target){
                minlen = min(minlen, right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minlen == INT_MAX?0:minlen;
    }
};
int main(){
    vector<int> nums = {2,3,1,2,4,3};
    Solution s;
    cout<<s.minSubArrayLen(7,nums)<<endl;
}