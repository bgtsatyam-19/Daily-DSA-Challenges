// Bitwise AND of Numbers Range 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int count = 0;
       while(left < right){
        left = left >>1;
        right = right >>1;
        count ++;

       }
       return left << count; 
    }
};
int main(){
    Solution obj;
    cout<<obj.rangeBitwiseAnd(5,7)<<endl;
    return 0;
}