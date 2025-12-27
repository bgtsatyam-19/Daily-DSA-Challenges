//Strange Printer
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = len == 1 ? 1 : dp[i][j - 1] + 1;

                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};  
int main(){
    Solution obj;
    string s="aaabbb";
    cout<<obj.strangePrinter(s)<<endl; //Output: 2
    return 0;
}