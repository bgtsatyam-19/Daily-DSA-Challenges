#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                ans=nums[i];
            }
            if(nums[i]==ans){
                count++;
            }
            else{
                count--;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums={2,2,1,1,1,2,2};
    Solution s;
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}
//majority elements solved using moore's voting algorithm
//time complexity O(n)
//space complexity O(1)