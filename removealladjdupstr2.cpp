//Remove All Adjacent Duplicates in String II
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({c, 1});
            }
        }
        string result = "";
        while (!st.empty()) {
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }
        return result;
    }
};
int main() {
    Solution s;
    string input = "deeedbbcccbdaa";
    int k = 3;
    string result = s.removeDuplicates(input, k);
    cout << "Result after removing duplicates: " << result << endl; 
    return 0;
}
