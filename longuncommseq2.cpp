//Longest Uncommon Subsequence II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        auto isSubsequence = [](const string& a, const string& b) {
            int i = 0, j = 0;
            while (i < a.size() && j < b.size()) {
                if (a[i] == b[j]) {
                    i++;
                }
                j++;
            }
            return i == a.size();
        };

        int maxLength = -1;
        for (int i = 0; i < strs.size(); ++i) {
            bool isUncommon = true;
            for (int j = 0; j < strs.size(); ++j) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) {
                maxLength = max(maxLength, static_cast<int>(strs[i].size()));
            }
        }
        return maxLength;
    }
};
int main(){
    Solution obj;
    vector<string> strs={"aba","cdc","eae"};
    cout<<obj.findLUSlength(strs)<<endl;
    return 0;
}