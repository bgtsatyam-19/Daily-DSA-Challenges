
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i= 0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j= i+1; j<nums.size(); j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int left= j+1;
            int right= nums.size()-1;
            while(left<right){
                long long sum = 1LL* nums[i]+nums[j]+nums[left]+nums[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    res.push_back({nums[i],nums[j], nums[left], nums[right] });
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,0,-1,0,-2,2};
    vector<vector<int>> res = s.fourSum(nums,0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}