//Find the Closest Palindrome
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;

        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len - 1) - 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (long long i = prefix - 1; i <= prefix + 1; i++) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());

            if (len % 2 == 0)
                candidates.insert(stoll(s + rev));
            else
                candidates.insert(stoll(s + rev.substr(1)));
        }

        long long ans = -1;

        for (long long x : candidates) {
            if (x == num) continue;
            if (ans == -1 ||
                abs(x - num) < abs(ans - num) ||
                (abs(x - num) == abs(ans - num) && x < ans)) {
                ans = x;
            }
        }
        return to_string(ans);
    }
};

int main() {
    Solution s;
    string n;
    cin >> n;
    cout << s.nearestPalindromic(n);
    return 0;
}
