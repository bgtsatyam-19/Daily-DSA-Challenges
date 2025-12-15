//shortest bridge
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        bool found = false;

        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) return;
            grid[x][y] = 2; 
            q.push({x, y});
            for (const auto& dir : directions) {
                dfs(x + dir.first, y + dir.second);
            }
        };

        for (int i = 0; i < n; ++i) {
            if (found) break;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                    break;
                }
            }
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (const auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                        if (grid[newX][newY] == 1) {
                            return steps;
                        }
                        if (grid[newX][newY] == 0) {
                            grid[newX][newY] = 2; 
                            q.push({newX, newY});
                        }
                    }
                }
            }
            ++steps;
        }
        return -1; 
    }
};
int main(){
    Solution obj;
    vector<vector<int>> grid={
        {0,1,0},
        {0,0,0},
        {0,0,1}
    };
    cout<<obj.shortestBridge(grid)<<endl; //Output: 2
    return 0;
}
