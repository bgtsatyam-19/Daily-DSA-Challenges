#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int index= abs(nums[i])-1;
            nums[index]=-abs(nums[index]);
        }
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums={4,3,2,7,8,2,3,1};
    vector<int> ans=s.findDisappearedNumbers(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}