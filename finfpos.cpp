//find first and last position of element in sorted array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = 0, right = nums.size() - 1;

        // Find first occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) {
            return result; // Target not found
        }
        result[0] = left;

        // Find last occurrence
        right = nums.size() - 1; // Reset right pointer
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        result[1] = right;

        return result;
    }
};
int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> target;

    Solution obj;
    vector<int> result = obj.searchRange(nums, target);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
