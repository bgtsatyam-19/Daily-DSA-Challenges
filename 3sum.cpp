#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       int n = nums.size();
       sort(nums.begin(), nums.end());
        for(int i = 0;i<n-2;i++){
            if(i > 0 && nums[i] == nums[i-1])
            continue;
             
             if(nums[i] > 0)  break;
        int left= i+1;
        int right= n-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum<0){
                left++;
            }
            else if(sum>0){
                right--;
            }
            else{
                result.push_back({nums[i], nums[left], nums[right]});
                while(left<right && nums[left] == nums[left+1]) left++;
                while(left<right && nums[right]== nums[right-1]) right--;

                left++;
                right--;
            } }
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums ={-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}