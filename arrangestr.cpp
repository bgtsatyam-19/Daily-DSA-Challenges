//Find All Anagrams in a String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size()<p.size()) return result;
        vector<int> pCount(26,0), sCount(26,0);
        for(int i=0;i<p.size();i++){
            pCount[p[i]-'a']++;
            sCount[s[i]-'a']++;
        }
        if(pCount==sCount) result.push_back(0);
        for(int i=p.size();i<s.size();i++){
            sCount[s[i]-'a']++;
            sCount[s[i-p.size()]-'a']--;
            if(sCount==pCount) result.push_back(i-p.size()+1);
        }
        return result;
    }
};
int main(){
    Solution obj;
    string s="cbaebabacd";
    string p="abc";
    vector<int> result=obj.findAnagrams(s,p);
    for(const auto& index:result){
        cout<<index<<" "; 
    }
    return 0;
}
