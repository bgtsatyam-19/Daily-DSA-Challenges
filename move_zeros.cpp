#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int lastnonzero=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[lastnonzero++],nums[i]);
        }
       } 
    }
};
int main(){
    Solution s;
    vector<int> nums={0,1,0,3,12};
    s.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
    return 0;
}