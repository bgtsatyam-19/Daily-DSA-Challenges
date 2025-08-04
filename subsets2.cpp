#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, temp, result);
        return result;
    }
    void subsetsWithDup(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            subsetsWithDup(nums, i + 1, temp, result);
            temp.pop_back();
        }
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,2};
    vector<vector<int>> ans=s.subsetsWithDup(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}