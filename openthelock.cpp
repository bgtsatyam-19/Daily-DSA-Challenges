//Open the Lock
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == target) return steps;
                for (int j = 0; j < 4; j++) {
                    string next = curr;
                    next[j] = (curr[j] - '0' + 1) % 10 + '0';
                    if (!dead.count(next)) {
                        q.push(next);
                        dead.insert(next);
                    }
                    next[j] = (curr[j] - '0' + 9) % 10 + '0';
                    if (!dead.count(next)) {
                        q.push(next);
                        dead.insert(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    cout << sol.openLock(deadends, target) << endl; // Output: 6
    return 0;
}
