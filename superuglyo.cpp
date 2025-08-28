#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);
        dp[0] = 1;
        int k = primes.size();
        vector<int> idx(k, 0); 
        vector<long long> val(primes.begin(), primes.end()); 

        for (int i = 1; i < n; i++) {
            long long nextUgly = *min_element(val.begin(), val.end());
            dp[i] = nextUgly;

            for (int j = 0; j < k; j++) {
                if (val[j] == nextUgly) {
                    idx[j]++;
                    val[j] = dp[idx[j]] * primes[j];
                }
            }
        }
        return (int)dp[n - 1];
    }
};

int main() {
    Solution obj;
    int n = 12;
    vector<int> primes = {2,7,13,19};
    cout << obj.nthSuperUglyNumber(n, primes) << endl; 
}
