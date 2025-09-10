//Valid Number
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
      bool isNumber(string s) {
        bool seenDigit = false, seenDot = false, seenExp = false;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') 
                    return false; 
            }
            else if (c == '.') {
                if (seenDot || seenExp) return false; 
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                seenDigit = false; 
            }
            else {
                return false;
            }
        }
        return seenDigit;   
    }  
};
int main(){
    Solution s;
    string s1="0.1";
    cout<<s.isNumber(s1);
}