//Longest Harmonious Subsequence
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int longest = 0;
        for (const auto& pair : count) {
            int num = pair.first;
            if (count.find(num + 1) != count.end()) {
                longest = max(longest, pair.second + count[num + 1]);
            }
        }
        return longest;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int result = solution.findLHS(nums);
    cout << "Length of the longest harmonious subsequence: " << result << endl;
    return 0;
}
