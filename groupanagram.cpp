#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& s: strs){
            string key= s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& p: mp){
            result.push_back(p.second);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result=s.groupAnagrams(strs);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}