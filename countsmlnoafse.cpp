//Count of Smaller Numbers After Self 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<int> sortedList;
        
        for (int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(sortedList.begin(), sortedList.end(), nums[i]) - sortedList.begin();
            result[i] = pos;
            sortedList.insert(sortedList.begin() + pos, nums[i]);
        }
        
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums={5,2,6,1};
    vector<int> ans=s.countSmaller(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}