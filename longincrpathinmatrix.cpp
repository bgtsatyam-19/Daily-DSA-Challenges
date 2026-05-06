//Longest Increasing Path in a Matrix
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxLength = 1;
        for (auto& dir : directions) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxLength = max(maxLength, 1 + dfs(matrix, dp, x, y));
            }
        }
        return dp[i][j] = maxLength;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> matrix={{9,9,4},{6,6,8},{2,1,1}};
    int ans=obj.longestIncreasingPath(matrix);
    cout<<ans<<endl;
    return 0;
}
