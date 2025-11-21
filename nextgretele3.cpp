//Next Greater Element III
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        int len = numStr.length();
        
        int i = len - 2;
        while (i >= 0 && numStr[i] >= numStr[i + 1]) {
            i--;
        }
        
        if (i < 0) {
            return -1; 
        }
        
        int j = len - 1;
        while (numStr[j] <= numStr[i]) {
            j--;
        }
        
        swap(numStr[i], numStr[j]);
        reverse(numStr.begin() + i + 1, numStr.end());
        
        long long result = stoll(numStr);
        return (result > INT_MAX) ? -1 : static_cast<int>(result);
    }
};
int main(){
    Solution obj;
    int n=1234;
    cout<<obj.nextGreaterElement(n)<<endl; 
    return 0;
}