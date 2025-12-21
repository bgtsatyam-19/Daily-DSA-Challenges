#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
        }
        int categories = hasLower + hasUpper + hasDigit;

        vector<int> repeats;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && password[j] == password[i]) j++;
            if (j - i >= 3) repeats.push_back(j - i);
            i = j;
        }

        int toAdd = max(0, 6 - n);
        int toDelete = max(0, n - 20);
        int replace = 0;

        for (int len : repeats) {
            replace += len / 3;
        }

        if (n <= 20) {
            return max(toAdd, 3 - categories) + replace;
        } else {
            int overLen = toDelete;
            for (int k = 1; k <= 3; ++k) {
                for (int i = 0; i < repeats.size() && overLen > 0; ++i) {
                    if (repeats[i] < 3 || repeats[i] % 3 != (k - 1)) continue;
                    int need = min(overLen, k);
                    repeats[i] -= need;
                    overLen -= need;
                    if (repeats[i] < 3) replace -= (repeats[i] + need) / 3;
                }
            }
            replace -= overLen / 3;

            return toDelete + max(3 - categories, replace);
        }

    }
};
int main(){
    Solution obj;
    string password="aA1";
    cout<<obj.strongPasswordChecker(password)<<endl; //Output: 3
    return 0;
}