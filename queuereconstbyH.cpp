//Queue Reconstruction by Height
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> queue;
        for (const auto& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        
        return queue;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> result = solution.reconstructQueue(people);
    
    cout << "Reconstructed Queue:" << endl;
    for (const auto& person : result) {
        cout << "[" << person[0] << ", " << person[1] << "]" << endl;
    }
    
    return 0;
}
