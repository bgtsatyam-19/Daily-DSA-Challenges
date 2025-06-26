
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                res[0] = m[target - nums[i]];
                res[1] = i;
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    vector<int> result = s.twoSum(nums, target);
    cout << "Result indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
