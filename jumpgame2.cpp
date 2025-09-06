#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            int jump = 0;
            int curr = 0;
            int maxReach = 0;
            for(int i=0; i<n-1; i++){
                maxReach = max(maxReach, i + nums[i]);
                if(i == curr){
                    jump++;
                    curr = maxReach;
                }
            }
            return jump;
        }
};
int main(){
    Solution s;
    vector<int> nums={2,3,1,1,4};
    cout<<s.jump(nums);
}