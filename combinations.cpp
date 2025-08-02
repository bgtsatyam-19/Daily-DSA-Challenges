#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> ans;
       vector<int> temp;
       backtrack(ans, temp, 1,n, k);
       return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>&temp, int start, int n, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;++i){
            temp.push_back(i);
            backtrack(ans, temp, i+1, n, k);
            temp.pop_back();
        }
    }
};
int main(){
    Solution s;
    vector<vector<int>> ans=s.combine(4,2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//this code is about combination problem in which we have to find all the possible combinations