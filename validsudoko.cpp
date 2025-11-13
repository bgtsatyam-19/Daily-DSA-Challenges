//valid sudoko
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.') continue;
                if(rows[i].count(c) || cols[j].count(c) || boxes[(i/3)*3 + j/3].count(c)){
                    return false;
                }
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[(i/3)*3 + j/3].insert(c);
            }
        }
        return true;
    }
};
int main(){
    Solution obj;
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
    bool result=obj.isValidSudoku(board);
    cout<<(result ? "Valid Sudoku" : "Invalid Sudoku")<<endl; //Output: Valid Sudoku
    return 0;
}