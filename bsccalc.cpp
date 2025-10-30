// Basic Calculator II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int calculate(string s) {
        int n = s.size();
        stack<int> stk;
        char sign = '+';
        int num = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push(-num);
                } else if (sign == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                } else if (sign == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }
                sign = c;
                num = 0;
            }
        }

        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
int main(){
    Solution obj;
    string s = "3+2*2";
    cout << obj.calculate(s) << endl; 
    return 0;
}