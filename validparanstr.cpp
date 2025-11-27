//Valid Parenthesis String
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  
        int high = 0; 

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(low - 1, 0);
                high--;
            } else { 
                low = max(low - 1, 0);
                high++;
            }

            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};
int main(){
    Solution obj;
    string s="(*)";
    cout<< (obj.checkValidString(s) ? "true" : "false") << endl; 
    return 0;
}