//smallest integer divisible by k
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1; 
        }

        int remainder = 0;
        for (int length = 1; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length; 
            }
        }
        return -1; 
    }
};
int main(){
    Solution obj;
    int k=3;
    cout<<obj.smallestRepunitDivByK(k)<<endl; 
    return 0;
}