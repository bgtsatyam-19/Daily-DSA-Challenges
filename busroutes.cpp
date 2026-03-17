//Bus Routes
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, vector<int>> stopToBuses;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        
        queue<pair<int, int>> q; // pair<bus, stops taken>
        unordered_set<int> visitedBuses;
        
        for (int bus : stopToBuses[source]) {
            q.push({bus, 1});
            visitedBuses.insert(bus);
        }
        // ...existing code...
        while (!q.empty()) {
            pair<int, int> front = q.front();
            int bus = front.first;
            int stops = front.second;
            q.pop();

            for (int stop : routes[bus]) {
                if (stop == target) return stops;
                
                for (int nextBus : stopToBuses[stop]) {
                    if (visitedBuses.find(nextBus) == visitedBuses.end()) {
                        visitedBuses.insert(nextBus);
                        q.push({nextBus, stops + 1});
                    }
                }
            }
        }
        
        return -1; 
    }
};  
int main() {
    Solution sol;
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1;
    int target = 6;
    cout << sol.numBusesToDestination(routes, source, target) << endl; // Output: 2
    return 0;
}
