#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }

        result += sign * num;
        return (int)result;
    }
};
int main() {
    Solution sol;
    string expression = "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(expression) << endl; // Output: 23    
    return 0;
}
