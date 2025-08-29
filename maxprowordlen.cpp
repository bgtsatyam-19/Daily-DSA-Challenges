#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> bestLen; 
        bestLen.reserve(words.size() * 2);

        for (const string& w : words) {
            int mask = 0;
            for (char c : w) mask |= 1 << (c - 'a');
            auto it = bestLen.find(mask);
            if (it == bestLen.end()) bestLen[mask] = (int)w.size();
            else if ((int)w.size() > it->second) it->second = (int)w.size();
        }

        int ans = 0;
        vector<pair<int,int>> items;
        items.reserve(bestLen.size());
        for (auto &p : bestLen) items.push_back(p);

        for (int i = 0; i < (int)items.size(); ++i) {
            for (int j = i + 1; j < (int)items.size(); ++j) {
                if ((items[i].first & items[j].first) == 0) {
                    int prod = items[i].second * items[j].second;
                    if (prod > ans) ans = prod;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> words={"abcw","baz","foo","bar","xtfn","abcdef"};
    int ans=s.maxProduct(words);
    cout<<ans;
}