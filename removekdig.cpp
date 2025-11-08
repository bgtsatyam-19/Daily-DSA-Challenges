// Remove K Digits
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";

        stack<char> stk;
        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }

        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());

        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        result = result.substr(nonZeroIndex);

        return result.empty() ? "0" : result;
    }
};
int main(){
    Solution obj;
    string num = "1432219";
    int k = 3;
    cout << obj.removeKdigits(num, k) << endl; 
    return 0;
}