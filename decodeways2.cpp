//Decode Ways II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        long long prev2 = 1;
        long long prev1 = ways1(s[0]);

        for (int i = 1; i < n; i++) {
            long long cur = (ways1(s[i]) * prev1) % MOD;
            cur = (cur + ways2(s[i - 1], s[i]) * prev2) % MOD;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    int ways1(char c) {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }

    int ways2(char a, char b) {
        if (a == '*' && b == '*') return 15;
        if (a == '*') return (b <= '6') ? 2 : 1;
        if (b == '*') {
            if (a == '1') return 9;
            if (a == '2') return 6;
            return 0;
        }
        int val = (a - '0') * 10 + (b - '0');
        return (val >= 10 && val <= 26) ? 1 : 0;
    }
};

int main() {
    Solution s;
    string str;
    cin >> str;
    cout << s.numDecodings(str);
    return 0;
}
