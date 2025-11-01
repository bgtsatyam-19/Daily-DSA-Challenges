//Unique Word Abbreviation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    if (rows == 0) return false;
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    function<bool(int, int, int)> dfs = [&](int r, int c, int index) {
        if (index == word.size()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
        if (visited[r][c] || board[r][c] != word[index]) return false;

        visited[r][c] = true;
        bool found = dfs(r + 1, c, index + 1) ||
                     dfs(r - 1, c, index + 1) ||
                     dfs(r, c + 1, index + 1) ||
                     dfs(r, c - 1, index + 1);
        visited[r][c] = false; 
        return found;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dfs(i, j, 0)) return true;
        }
    }
    return false;
}
};
int main(){
    Solution obj;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << (obj.exist(board, word) ? "true" : "false") << endl; // Output: true
    return 0;
}