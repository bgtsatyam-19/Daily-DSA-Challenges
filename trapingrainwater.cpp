//Trapping Rain Water
//using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int waterTrapped = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                waterTrapped += distance * boundedHeight;
            }
            st.push(i);
        }
        return waterTrapped;
    }
};
int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = s.trap(height);
    cout << "Total water trapped: " << result << endl; 
    return 0;
}

