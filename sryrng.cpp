//Summary ranges
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0];
        for (int i = 1; i <= n; ++i) {
            if (i < n && nums[i] == nums[i - 1] + 1) {
                continue;
            } else {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                if (i < n) {
                    start = nums[i];
                }
            }
        }
        return result;
    }
};
int main(){
    Solution obj;
    vector<int> nums={0,1,2,4,5,7};
    vector<string> result=obj.summaryRanges(nums);
    for(const auto& res:result){
        cout<<res<<endl; 
    }
    return 0;
}