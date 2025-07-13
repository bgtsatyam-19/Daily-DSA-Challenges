#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorvalue = x^y;
        int count =0;
        while(xorvalue){
            count += xorvalue & 1;
            xorvalue >>=1;
        }
        return count;
    }
};
int main(){
    Solution s;
    cout<<s.hammingDistance(1,4)<<endl;
    return 0;}