#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
     int a=0;
     int b=0;
     for(int num:nums){
        int temp=max(a,b+num);
        b=a;
        a=temp;
     }   
     return a;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,1};
    cout<<s.rob(nums)<<endl;
    return 0;
}
//in this code we are taking two variables a and b and we are taking max of a and b+num and then we are updating b=a and a=temp
//then we are returning a which is the maximum amount we can rob 
//time complexity is O(n)
//space complexity is O(1)