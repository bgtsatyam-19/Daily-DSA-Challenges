//The Skyline Problem
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.emplace_back(b[0], -b[2]); 
            events.emplace_back(b[1], b[2]);  
        }
        sort(events.begin(), events.end());

        multiset<int> heights = {0}; 
        vector<vector<int>> result;
        int prevHeight = 0;

        for (const auto& e : events) {
            if (e.second < 0) {
                heights.insert(-e.second); 
            } else {
                heights.erase(heights.find(e.second)); 
            }

            int currentHeight = *heights.rbegin(); 
            if (currentHeight != prevHeight) {
                result.push_back({e.first, currentHeight});
                prevHeight = currentHeight;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> skyline = s.getSkyline(buildings);
    for (const auto& point : skyline) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    return 0;
}