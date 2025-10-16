//Reverse String II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.length();i+=2*k){
            reverse(s.begin()+i,s.begin()+min(i+k,(int)s.length()));
        }
        return s;
    }
};
int main(){
    Solution obj;
    string s="abcdefg";
    int k=2;
    cout<<obj.reverseStr(s,k)<<endl;
    return 0;
}