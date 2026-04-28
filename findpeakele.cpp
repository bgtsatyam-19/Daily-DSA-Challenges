//Find Peak Element
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }

        return left;
    }
};
int main(){
    Solution obj;
    vector<int> nums={1,2,3,1};
    int ans=obj.findPeakElement(nums);
    cout<<ans<<endl;
    return 0;
}
