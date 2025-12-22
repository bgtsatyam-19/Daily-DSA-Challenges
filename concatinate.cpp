//Concatenated Words
#include<bits/stdc++.h>
using namespace std;        
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;

        for (const string& word : words) {
            if (canForm(word, wordSet)) {
                result.push_back(word);
            }
        }
        return result;
    }
private:
    bool canForm(const string& word, const unordered_set<string>& wordSet) {
        if (word.empty()) return false;

        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; 

        for (int i = 1; i <= n; ++i) {
            for (int j = (i == n ? 1 : 0); j < i; ++j) {
                if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main(){
    Solution obj;
    vector<string> words={"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> result=obj.findAllConcatenatedWordsInADict(words);
    for(const auto& res:result){
        cout<<res<<endl; //Output: catsdogcats dogcatsdog ratcatdogcat
    }
    return 0;
}

