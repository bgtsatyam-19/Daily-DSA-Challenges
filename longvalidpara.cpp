//Longest Valid Parentheses
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> indices;
        indices.push(-1); 

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            } else {
                indices.pop();
                if (indices.empty()) {
                    indices.push(i);
                } else {
                    maxLength = max(maxLength, i - indices.top());
                }
            }
        }

        return maxLength;
    }
};
int main(){
    Solution obj;
    string s=")()())";
    cout<<obj.longestValidParentheses(s)<<endl; 
    return 0;
}