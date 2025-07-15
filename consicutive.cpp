#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maxcount =0;
       int current =0;
       for(int num : nums){
        if(num == 1){
            current++;
            maxcount = max(maxcount , current);
        }
        else{
            current = 0;
        }
       } 
       return maxcount;
    }
};  
int main(){
    Solution s;
    vector<int> nums={1,1,0,1,1,1};
    cout<<s.findMaxConsecutiveOnes(nums)<<endl;
}