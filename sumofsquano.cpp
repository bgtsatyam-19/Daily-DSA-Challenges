//Sum of Square Numbers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left=0;
        long right=sqrt(c);
        while(left<=right){
            long sum=left*left+right*right;
            if(sum==c) return true;
            else if(sum<c) left++;
            else right--;
        }
        return false;
    }
};
int main(){
    Solution obj;
    int c=5;
    if(obj.judgeSquareSum(c)){
        cout<<"True"<<endl; //Output: True
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}