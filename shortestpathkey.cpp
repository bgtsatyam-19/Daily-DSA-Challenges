//Shortest Path to Get All Keys
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int startX = 0, startY = 0;
        int totalKeys = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = grid[i][j];

                if (ch == '@') {
                    startX = i;
                    startY = j;
                }

                if (ch >= 'a' && ch <= 'f') {
                    totalKeys = max(totalKeys, ch - 'a' + 1);
                }
            }
        }

        int finalMask = (1 << totalKeys) - 1;

        queue<vector<int>> q;
        q.push({startX, startY, 0});

        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false))
        );

        visited[startX][startY][0] = true;

        int steps = 0;

        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto curr = q.front();
                q.pop();

                int x = curr[0];
                int y = curr[1];
                int keys = curr[2];

                if (keys == finalMask) return steps;

                for (auto d : dirs) {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    int newKeys = keys;

                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;

                    char ch = grid[nx][ny];

                    if (ch == '#') continue;

                    if (ch >= 'a' && ch <= 'f') {
                        newKeys = keys | (1 << (ch - 'a'));
                    }

                    if (ch >= 'A' && ch <= 'F') {
                        if ((keys & (1 << (ch - 'A'))) == 0)
                            continue;
                    }

                    if (!visited[nx][ny][newKeys]) {
                        visited[nx][ny][newKeys] = true;
                        q.push({nx, ny, newKeys});
                    }
                }
            }
            steps++;
        }

        return -1; 
    }
};
int main() {
    Solution sol;
    vector<string> grid = {"@.a..", "###.#", "b.A.B"};
    cout << sol.shortestPathAllKeys(grid) << endl; // Output: 8
    return 0;
}
