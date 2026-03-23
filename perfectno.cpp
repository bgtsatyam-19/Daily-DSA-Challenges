//Perfect Number
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        
        int sum = 1; 
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i; 
                }
            }
        }
        
        return sum == num;
    }
};
int main() {
    Solution solution;
    int num = 28;
    bool isPerfect = solution.checkPerfectNumber(num);
    cout << num << (isPerfect ? " is a perfect number." : " is not a perfect number.") << endl;
    return 0;
}
