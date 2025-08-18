#include <bits/stdc++.h>
using namespace std;
class solution {
    public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>(n/3)){
                ans.push_back(it.first);
            }
        }
        return ans;
    }      
};
int main(){
    solution s;
    vector<int> nums={1,1,1,3,3,2,2,2};
    vector<int> ans=s.majorityElement(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}