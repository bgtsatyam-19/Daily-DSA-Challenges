//Reconstruct Original Digits from English
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        vector<int> charCount(26, 0);
        
        for (char c : s) {
            charCount[c - 'a']++;
        }

        count[0] = charCount['z' - 'a'];
        count[2] = charCount['w' - 'a'];
        count[4] = charCount['u' - 'a'];
        count[6] = charCount['x' - 'a'];
        count[8] = charCount['g' - 'a'];

        count[3] = charCount['h' - 'a'] - count[8];
        count[5] = charCount['f' - 'a'] - count[4];
        count[7] = charCount['s' - 'a'] - count[6];

        count[1] = charCount['o' - 'a'] - count[0] - count[2] - count[4];
        count[9] = charCount['i' - 'a'] - count[5] - count[6] - count[8];

        string result;
        for (int i = 0; i <= 9; ++i) {
            result += string(count[i], '0' + i);
        }
        
        return result;
    }
};
int main() {
    Solution obj;
    string s = "owoztneoer";
    cout << obj.originalDigits(s) << endl; 
    return 0;
}
