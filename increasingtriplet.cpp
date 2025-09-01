//Increasing Triplet Subsequence 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),f1=INT_MAX,f2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<f1)
            {
                f1=nums[i];
            }else if(nums[i]>f1 && nums[i]<f2)
            {
                f2=nums[i];
            }else if(nums[i]>f2)
            {
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4,5};
    cout<<s.increasingTriplet(nums);
}