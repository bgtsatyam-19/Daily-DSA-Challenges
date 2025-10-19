//Range Addition II

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()) return m*n;
        int minRow=m;
        int minCol=n;
        for(const auto& op:ops){
            minRow=min(minRow,op[0]);
            minCol=min(minCol,op[1]);
        }
        return minRow*minCol;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> ops={{2,2},{3,3}};
    int m=3,n=3;
    cout<<obj.maxCount(m,n,ops)<<endl; //Output:4
    return 0;
}