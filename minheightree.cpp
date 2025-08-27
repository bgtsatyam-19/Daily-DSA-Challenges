#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; 

        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            res.clear(); 
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                res.push_back(node);

                for (int nei : adj[node]) {
                    degree[nei]--;
                    if (degree[nei] == 1) q.push(nei);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution obj;
    int n = 4;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    vector<int> ans = obj.findMinHeightTrees(n, edges);
    for (int x : ans) cout << x << " "; 
}
