//permutation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, current, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.permute(nums);

    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
        