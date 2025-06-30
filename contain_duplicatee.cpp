#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int num:nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }

};
int main(){
    Solution s;
    vector<int> nums={1,2,3,1};
 cout << boolalpha << s.containsDuplicate(nums) << endl;
    return 0;
}