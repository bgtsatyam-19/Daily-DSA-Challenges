//Largest Palindrome Product
#include<bits/stdc++.h>
using namespace std;
class Solution { 
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9; 

        long long upperLimit = pow(10, n) - 1;
        long long lowerLimit = pow(10, n - 1);

        for (long long firstHalf = upperLimit; firstHalf >= lowerLimit; --firstHalf) {
            string strHalf = to_string(firstHalf);
            string revHalf = strHalf;
            reverse(revHalf.begin(), revHalf.end());
            long long palindrome = stoll(strHalf + revHalf);

            for (long long i = upperLimit; i * i >= palindrome; --i) {
                if (palindrome % i == 0) {
                    long long otherFactor = palindrome / i;
                    if (otherFactor >= lowerLimit && otherFactor <= upperLimit) {
                        return palindrome % 1337;
                    }
                }
            }
        }
        return -1; 
    }
};
int main(){
    Solution obj;
    int n = 2;
    cout<<obj.largestPalindrome(n)<<endl; //Output: 987
    return 0;
}
