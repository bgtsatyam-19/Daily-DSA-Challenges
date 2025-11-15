//Unique Substrings in Wraparound String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26,0);
        int count=0;
        for(int i=0;i<s.size();i++){
            if(i>0 && (s[i]-s[i-1]==1 || (s[i-1]=='z' && s[i]=='a'))){
                count++;
            }else{
                count=1;
            }
            dp[s[i]-'a']=max(dp[s[i]-'a'],count);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
int main(){
    Solution obj;
    string s="zab";
    cout<<obj.findSubstringInWraproundString(s)<<endl; //Output: 6
    return 0;
}
    