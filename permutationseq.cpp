#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
        nums.push_back(i);

        vector<int> fact(n);
        fact[0] =1;
        for(int i=1;i< n;i++)
        fact[i] = fact[i-1] *i;

        k = k-1;
        string ans ="";

        for(int i= n; i>= 1;i--){
        int idx = k /fact[i-1];
        ans += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);
        k %= fact[i-1];
        }
        return ans;
    }
};
int main(){
    Solution s;
    string ans=s.getPermutation(3,3);
    cout<<ans;
}