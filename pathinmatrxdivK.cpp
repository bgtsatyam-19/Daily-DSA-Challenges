#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
           const int MOD = 1'000'000'007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        int startRem = ((grid[0][0] % k) + k) % k;
        dp[0][0][startRem] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; 
                if (i > 0) {
                
                    for (int r = 0; r < k; ++r) {
                        if (dp[i-1][j][r] == 0) continue;
                        int newR = (r + grid[i][j]) % k;
                        if (newR < 0) newR += k;
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i-1][j][r]) % MOD;
                    }
                }
                if (j > 0) {
                    
                    for (int r = 0; r < k; ++r) {
                        if (dp[i][j-1][r] == 0) continue;
                        int newR = (r + grid[i][j]) % k;
                        if (newR < 0) newR += k;
                        dp[i][j][newR] = (dp[i][j][newR] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};
int main(){
    Solution obj;
    vector<vector<int>> grid = {{5,2,4},{3,0,1},{1,2,3}};
    int k = 3;
    cout << obj.numberOfPaths(grid, k) << endl;
    return 0;
}