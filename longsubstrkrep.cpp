//Longest Substring with At Least K Repeating Characters
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }
private:
    int helper(const string& s, int start, int end, int k) {
        if (end - start < k) return 0;

        vector<int> count(26, 0);
        for (int i = start; i < end; ++i) {
            count[s[i] - 'a']++;
        }

        for (int i = start; i < end; ++i) {
            if (count[s[i] - 'a'] < k) {
                int j = i + 1;
                while (j < end && count[s[j] - 'a'] < k) {
                    j++;
                }
                return max(helper(s, start, i, k), helper(s, j, end, k));
            }
        }
        return end - start;
    }
};
int main(){
    Solution obj;
    string s="aaabb";
    int k=3;
    cout<<obj.longestSubstring(s,k)<<endl; 
    return 0;
}