#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastseen;
        int maxlen =0;
        int left =0;
        for(int right =0; right<s.length();++right){
            char ch= s[right];
            if(lastseen.count(ch) && lastseen[ch] >=left){
                left = lastseen[ch]+1;
            }
            lastseen[ch] = right;
            maxlen = max(maxlen , right - left + 1);
        }
        return maxlen;
    }
};
int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
}