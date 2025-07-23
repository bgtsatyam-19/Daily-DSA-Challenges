#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long N =n;
        if(N<0){
            x  = 1 / x;
            N = -N;
        }
        double result = 1.0;
        while(N>0){
            if(N % 2 == 1){
                result *= x;
            }
            x *=x;
            N /=2;
        }
        return result;
    }
};
int main(){
    Solution s;
    cout<<s.myPow(2,-2)<<endl;
    return 0;
}