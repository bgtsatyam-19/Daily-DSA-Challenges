#include<bits/stdc++.h>
using namespace std;

            class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     int n=digits.size();
     for(int i=n-1;i>=0;i--){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        digits[i]=0;
     }
    digits.insert(digits.begin(),1);
    return digits;
    }
};
    
int main(){
    Solution s;
    vector<int> digits={9,9,9};
    vector<int> result=s.plusOne(digits);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
//the time complexity is O(n)
//the space complexity is O(1)
//this program is to add one to the digits of the vector and return the vector .