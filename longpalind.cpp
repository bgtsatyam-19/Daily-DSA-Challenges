#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0;        
        int maxLen = 1;       

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    start = left;
                    maxLen = len;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string input = "babad";
    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
