//Score of Parentheses
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (char c : s) {
            if (c == '(') {
                st.push(-1); 
            } else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1); 
                } else {
                    int score = 0;
                    while (!st.empty() && st.top() != -1) {
                        score += st.top();
                        st.pop();
                    }
                    st.pop(); 
                    st.push(2 * score); 
                }
            }
        }
        int totalScore = 0;
        while (!st.empty()) {
            totalScore += st.top();
            st.pop();
        }
        return totalScore;
    }

};
int main(){
    Solution s;
    string str = "(()(()))";
    int result = s.scoreOfParentheses(str);
    cout << "Score of parentheses for " << str << ": " << result << endl;
    return 0;
}

