//Permutation in String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26, 0), count2(26, 0);
        for (char c : s1) {
            count1[c - 'a']++;
        }
        int len1 = s1.length(), len2 = s2.length();
        for (int i = 0; i < len2; ++i) {
            count2[s2[i] - 'a']++;
            if (i >= len1) {
                count2[s2[i - len1] - 'a']--;
            }
            if (count1 == count2) {
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution obj;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << (obj.checkInclusion(s1, s2) ? "True" : "False") << endl; 
    return 0;
}