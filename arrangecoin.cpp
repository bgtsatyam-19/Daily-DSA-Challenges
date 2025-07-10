#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
       int left=0, right=n;
       while(left<=right){
        long mid=left+(right-left)/2;
        long long coinsused=mid*(mid+1)/2;
 
    if(coinsused==n) return mid;
    if(coinsused < n) left=mid+1;
    else right= mid-1;
           } 
           return right;
    }
};
int main(){
    Solution s;
    cout<<s.arrangeCoins(5)<<endl;
    return 0;
}