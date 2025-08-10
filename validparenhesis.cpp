#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                v.push_back(s[i]);
            }
            else if(s[i]==')' && !v.empty() && v.back()=='('){
                v.pop_back();
            }
            else if(s[i]=='}' && !v.empty() && v.back()=='{'){
                v.pop_back();
            }
            else if(s[i]==']' && !v.empty() && v.back()=='['){
                v.pop_back();
            }
            else{
                return false;
            }
        }
        return v.empty();
    }
};
int main(){
    Solution s;
    cout<<s.isValid("()");
}