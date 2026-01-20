//divide two integers
#include <iostream>
#include <climits>  
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }

        long long m = labs(dividend);
        long long n = labs(divisor);
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long quotient = 0;
        while (m >= n) {
            long long temp = n, multiple = 1;
            while (m >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            m -= temp;
            quotient += multiple;
        }

        return sign * quotient;
    }
};
int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;

    Solution obj;
    int result = obj.divide(dividend, divisor);

    cout << result << endl;
    return 0;
}
