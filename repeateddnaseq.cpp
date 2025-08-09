#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        string temp = s.substr(0,10);
        mp[temp]++;
        for(int i=10;i<s.size();i++){
            temp = temp.substr(1,9) + s[i];
            mp[temp]++;
        }
        for(auto it:mp){
            if(it.second > 1)
            ans.push_back(it.first);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans=s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}