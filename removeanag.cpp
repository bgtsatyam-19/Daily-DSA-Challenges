#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        for (auto& w : words) {
            string temp = w;
            sort(temp.begin(), temp.end());
            if (temp != prev) {
                ans.push_back(w);
                prev = temp;
            }
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> ans = obj.removeAnagrams(words);
    for (const auto& word : ans) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}