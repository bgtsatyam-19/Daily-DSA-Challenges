//24 Game
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int x : cards)
            nums.push_back(x);
        return solve(nums);
    }

    bool solve(vector<double>& nums) {
        if (nums.size() == 1)
            return abs(nums[0] - 24.0) < 1e-6;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }

                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> res;
        res.push_back(a + b);
        res.push_back(a - b);
        res.push_back(b - a);
        res.push_back(a * b);
        if (abs(b) > 1e-6) res.push_back(a / b);
        if (abs(a) > 1e-6) res.push_back(b / a);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> cards(4);
    for (int i = 0; i < 4; i++)
        cin >> cards[i];
    cout << (s.judgePoint24(cards) ? "true" : "false");
    return 0;
}
