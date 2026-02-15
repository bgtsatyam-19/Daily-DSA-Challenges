// Shortest Unsorted Continuous Subarray
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

        int start = 0, end = n - 1;

        while (start < n && nums[start] == sortedNums[start]) {
            start++;
        }

        while (end >= 0 && nums[end] == sortedNums[end]) {
            end--;
        }

        return (start >= end) ? 0 : (end - start + 1);
    }
};
int main() {
    Solution s;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int result = s.findUnsortedSubarray(nums);
    cout << "Length of the shortest unsorted subarray: " << result << endl;
    return 0;
}
