//01 Matrix
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            for (auto dir : directions) {

                int x = curr.first + dir.first;
                int y = curr.second + dir.second;

                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == -1) {
                    mat[x][y] = mat[curr.first][curr.second] + 1;
                    q.push({x, y});
                }
            }
        }

        return mat;
    }
};
int main() {

    Solution obj;

    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};

    vector<vector<int>> ans = obj.updateMatrix(mat);

    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
