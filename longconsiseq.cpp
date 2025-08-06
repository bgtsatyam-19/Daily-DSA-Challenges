#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }

    int ans =0;
    for(auto it:mp){
        if(mp.find(it.first-1) == mp.end()){
        int count=1;
        while(mp.find(it.first+count)!=mp.end()){
            count++;
        }
        ans = max(ans, count);
        }
    }

    return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={100,4,200,1,3,2};
    cout<<s.longestConsecutive(nums);
}