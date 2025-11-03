//Decode String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> resultStack;
        string result;
        int index = 0;

        while (index < s.length()) {
            if (isdigit(s[index])) {
                int count = 0;
                while (isdigit(s[index])) {
                    count = count * 10 + (s[index] - '0');
                    index++;
                }
                counts.push(count);
            } else if (s[index] == '[') {
                resultStack.push(result);
                result = "";
                index++;
            } else if (s[index] == ']') {
                string temp = resultStack.top();
                resultStack.pop();
                int repeatCount = counts.top();
                counts.pop();
                for (int i = 0; i < repeatCount; i++) {
                    temp += result;
                }
                result = temp;
                index++;
            } else {
                result += s[index];
                index++;
            }
        }
        return result;
    }
};  
int main() {
    Solution obj;
    string s = "3[a2[c]]";
    cout << obj.decodeString(s) << endl; // Output: accaccacc
    return 0;
}