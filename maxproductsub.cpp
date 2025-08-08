#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int minp=nums[0];
        int maxp=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(maxp,minp);
            }
            maxp=max(maxp*nums[i],nums[i]);
            minp=min(minp*nums[i],nums[i]);
            ans=max(ans,maxp);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={2,3,-2,4};
    cout<<s.maxProduct(nums);
}