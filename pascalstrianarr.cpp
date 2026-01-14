//pascal triangle
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; ++i) {
            triangle.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};
    
    int main() {
        int numRows;
        cin >> numRows;
        Solution sol;
        vector<vector<int>> result = sol.generate(numRows);
        
        for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        
        return 0;
    }