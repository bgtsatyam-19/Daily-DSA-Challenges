#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int sum=0;
        int right=numbers.size()-1;
        while(left<right){
            sum=numbers[left] + numbers[right];
            if(sum == target){
                return {left+1,right+1};
            }
            else if(sum<target){
            left++;
            }
            else{
                right --;
            }
        }
        return {};
    }
};
int main(){
    Solution s;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> result=s.twoSum(nums,target);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)
//this code is to find the two sum of the sorted array