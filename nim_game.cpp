#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;
    }
};
int main(){
    Solution s;
    cout<<boolalpha<<s.canWinNim(4)<<endl;
    return 0;
}