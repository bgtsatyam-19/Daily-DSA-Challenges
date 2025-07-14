#include<iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int m =0;
        while(temp > 0){
            m = (m << 1) | 1;
            temp >>=1;
        }
        return num^m;
    }
};
int main(){
    Solution s;
    cout<<s.findComplement(5)<<endl;
}