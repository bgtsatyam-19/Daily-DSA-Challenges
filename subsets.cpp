#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i=0;i<nums.size();i++){
            int n=ans.size();
            for(int j=0;j<n;j++){
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=s.subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}