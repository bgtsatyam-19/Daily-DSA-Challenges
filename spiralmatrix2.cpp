#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int num=1;
    int left=0;
    int right= n-1;
    int top= 0;
    int bottom= n-1;
    while(num <= n*n){
        for(int i=left; i<=right;i++)
        matrix[top][i] = num++;
        top++;
        for(int i=top;i<=bottom;i++)
        matrix[i][right] = num++;
        right--;
        for(int i=right;i>=left;i--)
        matrix[bottom][i] = num++;
        bottom--;
        for(int i=bottom;i>= top;i--)
        matrix[i][left]= num++;
        left++;
    }
    return matrix;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix=s.generateMatrix(3);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
