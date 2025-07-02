#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        istringstream iss(s);
        string word;
        int i = 0;

        while (iss >> word) {
            if (i == pattern.size()) return false;

            char c = pattern[i];

            if ((mp.count(c) && mp[c] != word) ||
                (rev.count(word) && rev[word] != c))
                return false;

            mp[c] = word;
            rev[word] = c;
            i++;
        }

        return i == pattern.size();
    }
};
int main(){
    Solution s;
    cout<<boolalpha<<s.wordPattern("abba","dog cat cat dog")<<endl;
    return 0;
}