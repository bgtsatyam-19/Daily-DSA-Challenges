#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval=INT_MAX;
        int sum=0;
        for(int num : nums){
            sum += num;
            minval = min(minval , num);
        }
        return sum - nums.size()*minval;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    cout<<s.minMoves(nums)<<endl;
}