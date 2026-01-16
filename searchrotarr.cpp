//seacrch in rotated sorted array
#include <iostream>
#include <vector>
using namespace std;
class solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Target is in the left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else { // Target is in the right half
                    left = mid + 1;
                }
            } else { // Right half is sorted
                // Target is in the right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else { // Target is in the left half
                    right = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
int main() {
    solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int result = sol.search(nums, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}
