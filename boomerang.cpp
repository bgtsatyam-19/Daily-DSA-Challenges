#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int total = 0;

        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> distanceCount;

            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distsq = dx * dx + dy * dy;

                distanceCount[distsq]++;
            }

            for (auto& [dist, count] : distanceCount) {
                total += count * (count - 1);
            }
        }

        return total;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    cout << s.numberOfBoomerangs(points) << endl;
    return 0;
}
