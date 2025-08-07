#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
        }
        return 0;
    }
};
int main(){
    Solution s;
    vector<int> nums={4,1,2,1,2};
    cout<<s.singleNumber(nums);
}