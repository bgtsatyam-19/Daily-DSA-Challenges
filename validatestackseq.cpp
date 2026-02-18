//Validate Stack Sequences
//Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; 
        for (int x : pushed) {
            st.push(x); 
            while (!st.empty() && st.top() == popped[j]) {
                st.pop(); 
                j++; 
            }
        }
        return st.empty(); 
    }
};
int main() {
    Solution s;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    bool result = s.validateStackSequences(pushed, popped);
    cout << "Is the stack sequence valid? " << (result ? "Yes" : "No") << endl;
    return 0;
}
