//Reverse Substrings Between Each Pair of Parentheses
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                current += c;
            }
        }
        return current;
    }
};
int main() {
    Solution s;
    string input = "(u(love)i)";
    string result = s.reverseParentheses(input);
    cout << "Reversed string: " << result << endl; 
    return 0;
}

