#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int top= 0;
        int bottom = matrix.size()-1;
        int left =0;
        int right = matrix[0].size() -1;
        while(top <= bottom && left <= right){
            for(int col= left;col<=right;++col)
            result.push_back(matrix[top][col]);
            top++;
            for(int row= top;row<= bottom;++row)
            result.push_back(matrix[row][right]);
            right--;
            if(top <= bottom){
                for(int col= right;col>= left;--col)
                result.push_back(matrix[bottom][col]);
                bottom--;
            }
            if(left <= right){
                for(int row= bottom; row>=top;--row)
                result.push_back(matrix[row][left]);
                left++;
            }
        }
        return result;

    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result=s.spiralOrder(matrix);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}