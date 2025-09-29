// add two numbers
#include <iostream>
using namespace std;    
class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1; 
            a = a ^ b;                
            b = carry;               
        }
        return a;
    }
};
int main() {
    Solution sol;
    int a = 5, b = 7;
    cout << "Sum of " << a << " and " << b << " is: " << sol.add(a, b) << endl;
    return 0;
}