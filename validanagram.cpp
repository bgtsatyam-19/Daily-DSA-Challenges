//Valid Anagram
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto it:m1){
            if(m2.find(it.first)==m2.end() || m2[it.first]!=it.second){
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution obj;
    string s, t;
    cout << "Enter first string: ";
    getline(cin, s);
    cout << "Enter second string: ";
    getline(cin, t);

    if (obj.isAnagram(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}