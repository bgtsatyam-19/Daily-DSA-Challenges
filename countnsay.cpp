//Count and Say
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
     string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string curr = "";
            int count = 1;
            for (int j = 1; j <= res.size(); j++) {
                if (j < res.size() && res[j] == res[j - 1]) {
                    count++;
                } else {
                    curr += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            res = curr;
        }
        return res;
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.countAndSay(n) << endl;
    return 0;
}
