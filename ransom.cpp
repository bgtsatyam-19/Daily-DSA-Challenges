#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        for(char ch : magazine)
         freq[ch-'a']++;
         for(char ch: ransomNote){
         if(freq[ch- 'a']==0)
         return false;
         freq[ch-'a']--;}
         return true;
    }
};
int main(){
    Solution s;
    string ransomNote="aa",magazine="ab";
    cout<<boolalpha<<s.canConstruct(ransomNote,magazine);
}