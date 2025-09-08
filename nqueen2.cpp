#include<bits/stdc++.h>
using namespace std;
class Solution {
    int count = 0;
    vector<int> colUsed, diag1Used, diag2Used;
    int N;

public:
    int totalNQueens(int n) {
        N = n;
        colUsed.assign(n, 0);
        diag1Used.assign(2*n, 0);  
        diag2Used.assign(2*n, 0);   
        backtrack(0);
        return count;
    }

    void backtrack(int row) {
        if (row == N) {
            count++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (colUsed[col] || diag1Used[row - col + N] || diag2Used[row + col])
                continue;

            colUsed[col] = diag1Used[row - col + N] = diag2Used[row + col] = 1;

            backtrack(row + 1);

            colUsed[col] = diag1Used[row - col + N] = diag2Used[row + col] = 0;
        }
    }
};
int main(){
    int n = 4;
    Solution obj;
    cout<<obj.totalNQueens(n)<<endl;
}