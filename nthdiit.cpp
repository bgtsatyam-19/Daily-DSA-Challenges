//Nth Digit
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / digitLength;
        string s = to_string(start);
        return s[(n - 1) % digitLength] - '0';
    }
};
int main(){
    Solution obj;
    int n=11;
    cout<<obj.findNthDigit(n)<<endl; 
    return 0;
}