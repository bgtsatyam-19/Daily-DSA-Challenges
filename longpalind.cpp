#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
for(char ch:s)
freq[ch]++;

int length=0;
bool hasodd=false;

for(const auto& pair : freq){
    int count=pair.second;
    length +=(count/2)*2;
    if(count %2 == 1) hasodd=true;
}
if(hasodd) length +=1;
return length;
    }
};
int main()
{
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.longestPalindrome(s)<<endl;
    return 0;
}