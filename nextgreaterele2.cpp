//Next Greater Element II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // Stack to store indices

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n]; // Circular indexing

            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num; // Update the result for the index at the top of the stack
                st.pop(); // Pop the index from the stack
            }

            if (i < n) { // Only push indices from the first pass
                st.push(i);
            }
        }

        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 1};
    vector<int> result = s.nextGreaterElements(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
