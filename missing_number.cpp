#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
   int n=nums.size();
   int expectedsum=n*(n+1)/2;
   int actualsum=accumulate(nums.begin(), nums.end(), 0 );
   return expectedsum-actualsum;     
    }
};
int main(){
    Solution s;
    vector<int> nums={3,0,1};
    cout<<s.missingNumber(nums)<<endl;
    return 0;
}