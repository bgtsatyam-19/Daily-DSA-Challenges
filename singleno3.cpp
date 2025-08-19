#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long xorsum = 0;
        for (int num : nums) xorsum ^= num;

        long long diff = xorsum & (-xorsum);

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & diff) a ^= num;
            else b ^= num;
        }
        return {a, b}; 
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,1,3,2,5};
    vector<int> ans=s.singleNumber(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}