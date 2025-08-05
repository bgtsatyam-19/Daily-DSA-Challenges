#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        if(n == 0 || s[0] == '0') return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1] =s[0] == '0'? 0:1;
        for(int i=2;i<=n;i++){
            if(s[i-1] != '0'){
                 dp[i] += dp[i-1];
            }
            int conv = stoi(s.substr(i-2, 2));
            if(conv >= 10 && conv <=26){
                dp[i] +=dp[i-2];
            }
        }
        return dp[n];
    }
};
int main(){
    Solution s;
    cout<<s.numDecodings("12");
}