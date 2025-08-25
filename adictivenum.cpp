#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n / 2; i++) {
            if (num[0] == '0' && i > 1) break; 
            long long first = stoll(num.substr(0, i));

            for (int j = 1; max(i, j) <= n - i - j; j++) {
                if (num[i] == '0' && j > 1) break;
                long long second = stoll(num.substr(i, j));

                if (check(num.substr(i + j), first, second)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool check(string num, long long first, long long second) {
        if (num.empty()) return true;

        long long sum = first + second;
        string s = to_string(sum);

        if (num.rfind(s, 0) == 0) {
            return check(num.substr(s.size()), second, sum);
        }
        return false;
    }
};

int main() {
    string num = "112358";
    Solution obj;
    cout << obj.isAdditiveNumber(num) << endl; // ✅ fixed
}
