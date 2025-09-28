//Length of Last Word 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};
int main() {
    Solution s;
    string str = "Hello World";
    cout << s.lengthOfLastWord(str) << endl; 
    return 0;
}