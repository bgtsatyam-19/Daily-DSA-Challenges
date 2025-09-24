#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stack(k, 0);
        int top = -1, remain = n;
        for (int i = 0; i < n; i++, remain--) {
            while (top >= 0 && stack[top] < nums[i] && top + 1 + remain > k) {
                top--;
            }
            if (top + 1 < k) {
                stack[++top] = nums[i];
            }
        }
        return stack;
    }
        bool lexCompare(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++; j++;
        }
        return j == b.size() || (i < a.size() && a[i] > b[j]);
    }
    vector<int> merge(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> res;
        while (i < a.size() || j < b.size()) {
            if (lexCompare(a, i, b, j)) {
                res.push_back(a[i++]);
            } else {
                res.push_back(b[j++]);
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int m = nums1.size(), n = nums2.size();
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> seq1 = maxSubsequence(nums1, i);
            vector<int> seq2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(seq1, seq2);
            if (candidate > best) best = candidate;
        }
        return best;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    vector<int> ans = s.maxNumber(nums1, nums2, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}