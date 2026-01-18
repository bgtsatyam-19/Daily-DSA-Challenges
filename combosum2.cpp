//combinational sum 2
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, result); // Move to the next index
            current.pop_back();
        }
    }
};
int main() {
    int n, target;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }
    cin >> target;

    Solution sol;
    vector<vector<int>> combinations = sol.combinationSum2(candidates, target);

    for (const auto& combo : combinations) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
