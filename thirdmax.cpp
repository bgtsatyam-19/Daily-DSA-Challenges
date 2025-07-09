#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num : nums)
{
    s.insert(num);
    if(s.size() > 3){
        s.erase(s.begin());
    }
} 
if(s.size() == 3){
    return *s.begin();
} 
return *s.rbegin();
  }
};
int main(){
    Solution s;
    vector<int> nums={3,2,1};
    cout<<s.thirdMax(nums)<<endl;
}