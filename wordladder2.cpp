//word ladder II
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end()) return result;

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> levels;
        queue<string> q;
        q.push(beginWord);
        levels[beginWord] = 0;
        int level = 0;
        bool foundEnd = false;

        while (!q.empty() && !foundEnd) {
            level++;
            int size = q.size();
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();

                for (int j = 0; j < word.size(); ++j) {
                    string newWord = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        newWord[j] = c;
                        if (wordSet.find(newWord) != wordSet.end()) {
                            if (levels.find(newWord) == levels.end()) {
                                levels[newWord] = level;
                                q.push(newWord);
                                visitedThisLevel.insert(newWord);
                            }
                            if (levels[newWord] == level) {
                                parents[newWord].push_back(word);
                            }
                            if (newWord == endWord) {
                                foundEnd = true;
                            }
                        }
                    }
                }
            }
            for (const string& w : visitedThisLevel) {
                wordSet.erase(w);
            }
        }

        if (foundEnd) {
            vector<string> path;
            function<void(const string&)> backtrack = [&](const string& word) {
                path.push_back(word);
                if (word == beginWord) {
                    vector<string> tempPath = path;
                    reverse(tempPath.begin(), tempPath.end());
                    result.push_back(tempPath);
                } else {
                    for (const string& parent : parents[word]) {
                        backtrack(parent);
                    }
                }
                path.pop_back();
            };
            backtrack(endWord);
        }

        return result;
    }
};
int main() {
    Solution obj;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> result = obj.findLadders(beginWord, endWord, wordList);
    for (const auto& path : result) {
        for (const auto& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
