#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
          int m = board.size(), n = board[0].size();
        vector<int> dirs = {-1,0,1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0;
                for(int dx:dirs){
                    for(int dy:dirs){
                        if(dx==0 && dy==0) continue;
                        int ni=i+dx, nj=j+dy;
                        if(ni>=0 && ni<m && nj>=0 && nj<n && abs(board[ni][nj])==1){
                            live++;
                        }
                    }
                }
                if(board[i][j]==1 && (live<2 || live>3)){
                    board[i][j] = -1; 
                }
                if(board[i][j]==0 && live==3){
                    board[i][j] = 2; 
                }
            }
        }
                for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>0) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
};
int main(){
    Solution obj;
    vector<vector<int>> board={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    obj.gameOfLife(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}