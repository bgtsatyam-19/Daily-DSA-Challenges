#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toHex(int num) {
     if(num==0) return "0";

     string hex="";
     unsigned int n=num;
     string hexchars="0123456789abcdef";
    while(n>0){
        int rem=n & 15;
        hex =hexchars[rem]+hex;
        n >>=4;
    }   
    return hex;
    }
};
int main(){
    Solution obj;
    cout<<obj.toHex(26);
    return 0;
}
