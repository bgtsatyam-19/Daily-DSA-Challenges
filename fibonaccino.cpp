//Fibonacci Number
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
int main() {
    Solution solution;
    int n = 10;
    int result = solution.fib(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}
