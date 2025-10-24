// String to Integer (atoi)
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && isspace(s[i])) i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result < INT_MIN) return INT_MIN;
            if (sign * result > INT_MAX) return INT_MAX;
            i++;
        }
        return sign * result;
    }
};
int main() {
    Solution obj;
    string s = "   -42";
    cout << obj.myAtoi(s) << endl; // Output: -42
    return 0;
}