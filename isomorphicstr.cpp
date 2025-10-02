//isomorphic strings
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char> m1,m2;
        for(int i=0;i<s.length();i++){
            if(m1.find(s[i])==m1.end() && m2.find(t[i])==m2.end()){
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else if(m1.find(s[i])!=m1.end() && m2.find(t[i])!=m2.end()){
                if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
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

    if (obj.isIsomorphic(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}