//Remove Invalid Parentheses
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftToRemove = 0, rightToRemove = 0;
        for (char c : s) {
            if (c == '(') {
                leftToRemove++;
            } else if (c == ')') {
                if (leftToRemove > 0) {
                    leftToRemove--;
                } else {
                    rightToRemove++;
                }
            }
        }

        unordered_set<string> result;
        backtrack(s, 0, leftToRemove, rightToRemove, result);
        return vector<string>(result.begin(), result.end());
    }
private:
    void backtrack(const string& s, int start, int leftToRemove, int right
ToRemove, unordered_set<string>& result) {
        if (leftToRemove == 0 && rightToRemove == 0) {
            if (isValid(s)) {
                result.insert(s);
            }
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;

            if (s[i] == '(' && leftToRemove > 0) {
                string next = s.substr(0, i) + s.substr(i + 1);
                backtrack(next, i, leftToRemove - 1, rightToRemove, result);
            } else if (s[i] == ')' && rightToRemove > 0) {
                string next = s.substr(0, i) + s.substr(i + 1);
                backtrack(next, i, leftToRemove, rightToRemove - 1, result);
            }
        }
    }
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
};
int main(){
    Solution obj;
    string s="()())()";
    vector<string> result=obj.removeInvalidParentheses(s);
    for(const auto& res:result){
        cout<<res<<endl; //Output: (())()  ()()()
    }
    return 0;
}
