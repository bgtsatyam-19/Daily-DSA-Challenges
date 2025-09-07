#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> colUsed, diag1Used, diag2Used;
    int N;

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        board = vector<string>(n, string(n, '.'));
        colUsed.assign(n, 0);
        diag1Used.assign(2*n, 0);  
        diag2Used.assign(2*n, 0);  
        backtrack(0);
        return ans;
    }

    void backtrack(int row) {
        if (row == N) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            if (colUsed[col] || diag1Used[row - col + N] || diag2Used[row + col])
                continue;

            board[row][col] = 'Q';
            colUsed[col] = diag1Used[row - col + N] = diag2Used[row + col] = 1;

            backtrack(row + 1);

            board[row][col] = '.';
            colUsed[col] = diag1Used[row - col + N] = diag2Used[row + col] = 0;
        }
    }
};
int main(){
    Solution obj;
    int n=4;
    vector<vector<string>> ans=obj.solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";}
        cout<<endl;
    }
}
