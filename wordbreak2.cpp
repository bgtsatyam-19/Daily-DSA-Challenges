//Word Break II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        function<vector<string>(int)> backtrack = [&](int start) {
            if (memo.find(start) != memo.end()) {
                return memo[start];
            }

            vector<string> sentences;
            if (start == s.size()) {
                sentences.push_back("");
                return sentences;
            }

            for (int end = start + 1; end <= s.size(); ++end) {
                string word = s.substr(start, end - start);
                if (wordSet.find(word) != wordSet.end()) {
                    vector<string> subSentences = backtrack(end);
                    for (const string& subSentence : subSentences) {
                        string space = subSentence.empty() ? "" : " ";
                        sentences.push_back(word + space + subSentence);
                    }
                }
            }

            memo[start] = sentences;
            return sentences;
        };

        return backtrack(0);
    }
};
int main(){
    Solution obj;
    string s="catsanddog";
    vector<string> wordDict={"cat","cats","and","sand","dog"};
    vector<string> result=obj.wordBreak(s,wordDict);
    for(const auto& res:result){
        cout<<res<<endl; 
    }
    return 0;
}
