//Random Pick Index
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;
class Solution {
public:
    unordered_map<int, vector<int>> indexMap;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        const vector<int>& indices = indexMap[target];
        int randomIndex = rand() % indices.size();
        return indices[randomIndex];
    }
};  
int main() {
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution sol(nums);
    cout << sol.pick(3) << endl; // Randomly returns an index of the target value (0-based)
    return 0;
}