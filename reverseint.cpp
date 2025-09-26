//Longest Common Prefix 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            while(strs[i].find(ans) != 0){
                ans = ans.substr(0, ans.size() - 1);
            }
        }
        return ans;
    }
};  
int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = s.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}