#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater.count(num) ? nextGreater[num] : -1);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}
