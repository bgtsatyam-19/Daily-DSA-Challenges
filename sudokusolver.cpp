#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<unordered_set<int>> row, col, box;

public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9);
        col.resize(9);
        box.resize(9);

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i].insert(num);
                    col[j].insert(num);
                    box[(i/3)*3 + j/3].insert(num);
                }
            }
        }
        backtrack(board, 0, 0);
    }

    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if(r == 9) return true;
        if(c == 9) return backtrack(board, r+1, 0);
        if(board[r][c] != '.') return backtrack(board, r, c+1);

        for(int num=1; num<=9; num++) {
            int b = (r/3)*3 + c/3;
            if(row[r].count(num) || col[c].count(num) || box[b].count(num))
                continue;

            board[r][c] = num + '0';
            row[r].insert(num);
            col[c].insert(num);
            box[b].insert(num);

            if(backtrack(board, r, c+1)) return true;

            board[r][c] = '.';
            row[r].erase(num);
            col[c].erase(num);
            box[b].erase(num);
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'}, 
        {'6','.','.','1','9','5','.','.','.'}, 
        {'.','9','8','.','.','.','.','6','.'}, 
        {'8','.','.','.','6','.','.','.','3'}, 
        {'4','.','.','8','.','3','.','.','1'}, 
        {'7','.','.','.','2','.','.','.','6'}, 
        {'.','6','.','.','.','.','2','8','.'}, 
        {'.','.','.','4','1','9','.','.','5'}, 
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution obj;
    obj.solveSudoku(board);
    for(auto i: board) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}