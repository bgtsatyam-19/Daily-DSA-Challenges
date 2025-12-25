//tag validator
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        int i = 0, n = code.size();

        while (i < n) {
            if (i > 0 && st.empty()) return false;

            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                int k = code.find("]]>", j);
                if (k == string::npos) return false;
                i = k + 3;
            } 
            else if (code[i] == '<') {
                if (i + 1 < n && code[i + 1] == '/') {
                    int j = i + 2;
                    int k = code.find('>', j);
                    if (k == string::npos) return false;
                    string tag = code.substr(j, k - j);
                    if (st.empty() || st.top() != tag) return false;
                    st.pop();
                    i = k + 1;
                } 
                else {
                    int j = i + 1;
                    int k = code.find('>', j);
                    if (k == string::npos) return false;
                    string tag = code.substr(j, k - j);
                    if (tag.size() < 1 || tag.size() > 9) return false;
                    for (char c : tag)
                        if (c < 'A' || c > 'Z') return false;
                    st.push(tag);
                    i = k + 1;
                }
            } 
            else {
                i++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    string code;
    getline(cin, code);
    cout << (s.isValid(code) ? "true" : "false");
    return 0;
}
