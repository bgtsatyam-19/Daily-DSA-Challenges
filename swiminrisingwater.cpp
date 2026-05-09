//Swim in Rising Water
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = max(grid[0][0], grid[n - 1][n - 1]);
        int right = n * n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSwim(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
private:
    bool canSwim(const vector<vector<int>>& grid, int time) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1) {
                return true;
            }

            for (const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (isValid(newX, newY, n) && !visited[newX][newY] && grid[newX][newY] <= time) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        return false;
    }

    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};

    int result = sol.swimInWater(grid);
    cout << "Minimum time to swim from top-left to bottom-right is: " << result << endl;

    return 0;
}
