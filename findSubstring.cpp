#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string,int> wordMap;
        for(auto &w : words) wordMap[w]++;

        for(int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string,int> seen;

            for(int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if(wordMap.find(word) != wordMap.end()) {
                    seen[word]++;
                    count++;

                    while(seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if(count == wordCount) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> ans = sol.findSubstring(s, words);

    for(int idx : ans) cout << idx << " ";
    return 0;
}
