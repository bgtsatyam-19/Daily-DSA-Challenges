//Optimal Division
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }
        if (nums.size() == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string result = to_string(nums[0]) + "/(";
        for (size_t i = 1; i < nums.size(); ++i) {
            result += to_string(nums[i]);
            if (i != nums.size() - 1) {
                result += "/";
            }
        }
        result += ")";
        return result;
    }
};  
int main(){
    Solution obj;
    vector<int> nums={1000,100,10,2};
    cout<<obj.optimalDivision(nums)<<endl; 
    return 0;
}