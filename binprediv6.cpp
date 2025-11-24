//binary prefix division by 6
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy6(vector<int>& A) {
        vector<bool> result;
        int mod = 0;
        for (int bit : A) {
            mod = ((mod << 1) + bit) % 6;
            result.push_back(mod == 0);
        }
        return result;
    }
};
int main(){
    Solution obj;
    vector<int> A = {1,0,1,1,1};
    vector<bool> result = obj.prefixesDivBy6(A);
    for (bool val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}