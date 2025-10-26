//Generate Parentheses
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

    void backtrack(vector<string> &result, string &current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }
        if (open < max) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max);
            current.pop_back();
        }
    }
};
int main(){
    Solution obj;
    int n=3;
    vector<string> result=obj.generateParenthesis(n);
    for(const auto& paren:result){
        cout<<paren<<endl; 
    }
    return 0;
}