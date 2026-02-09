//Baseball Game
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (const string& op : ops) {
            if (op == "C") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (op == "D") {
                if (!s.empty()) {
                    s.push(2 * s.top());
                }
            } else if (op == "+") {
                if (s.size() >= 2) {
                    int top1 = s.top(); s.pop();
                    int top2 = s.top();
                    s.push(top1); // Push back the first top
                    s.push(top1 + top2);
                }
            } else {
                s.push(stoi(op));
            }
        }
        int totalPoints = 0;
        while (!s.empty()) {
            totalPoints += s.top();
            s.pop();
        }
        return totalPoints;
    }
};
int main() {
    Solution solution;
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << solution.calPoints(ops) << endl; // Output: 30
    return 0;
}
