//Dota2 Senate
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while (!r.empty() && !d.empty()) {
            int r_index = r.front();
            int d_index = d.front();
            r.pop();
            d.pop();
            if (r_index < d_index)
                r.push(r_index + n);
            else
                d.push(d_index + n);
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};
int main() {
    Solution sol;
    string senate = "RD";
    cout << sol.predictPartyVictory(senate) << endl; // Output: "Radiant"
    return 0;
}