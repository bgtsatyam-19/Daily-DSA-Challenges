#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;

        int same = k * 1;
        int diff = k * (k - 1);

        for (int i = 3; i <= n; i++) {
            int prev_diff = diff;
            diff = (same + diff) * (k - 1);
            same = prev_diff;
        }

        return same + diff;
    }
};

int main(){
    Solution s;
    cout<<s.numWays(3,4)<<endl;
    return 0;
}