//Minimum Window Substring
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char,int> need, have;
        for (char c : t) need[c]++;

        int haveCount = 0, needCount = t.size();
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            have[c]++;
            if (need.count(c) && have[c] <= need[c]) {
                haveCount++;
            }
            while (haveCount == needCount) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                have[leftChar]--;
                if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                    haveCount--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }  
};
int main(){
    Solution s;
    string s1="ADOBECODEBANC",t="ABC";
    cout<<s.minWindow(s1,t);
}