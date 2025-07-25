#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach= 0;
        for(int i=0;i< nums.size();++i){
            if(i > maxreach)
            return false;
            maxreach = max(maxreach , i + nums[i]);
            if(maxreach >= nums.size()-1)
            return true;
        }
        return true;
    }
};
int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution obj;
    cout<<obj.canJump(nums)<<endl;
    return 0;
}