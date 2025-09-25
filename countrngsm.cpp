#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return mergeSort(prefix, 0, n + 1, lower, upper);
    }

private:
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) +
                    mergeSort(prefix, mid, right, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long long> temp;
        for (int i = left; i < mid; i++) {
            while (k < right && prefix[k] - prefix[i] < lower) k++;
            while (j < right && prefix[j] - prefix[i] <= upper) j++;
            while (t < right && prefix[t] < prefix[i]) temp.push_back(prefix[t++]);
            temp.push_back(prefix[i]);
            count += (j - k);
        }
        while (t < right) temp.push_back(prefix[t++]);
        copy(temp.begin(), temp.end(), prefix.begin() + left);
        return count;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    int ans = s.countRangeSum(nums, lower, upper);
    cout << ans << endl; 
    return 0;
}