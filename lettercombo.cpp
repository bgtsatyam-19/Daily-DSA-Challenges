//Letter Combinations of a Phone Number
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;
        backtrack(digits, 0, mapping, current, result);
        return result;
    }

    void backtrack(string &digits, int index, vector<string> &mapping, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            backtrack(digits, index + 1, mapping, current, result);
            current.pop_back();
        }
    }
};
int main(){
    Solution obj;
    string digits="23";
    vector<string> result=obj.letterCombinations(digits);
    for(const auto& combo:result){
        cout<<combo<<endl; 
    }
    return 0;
}
