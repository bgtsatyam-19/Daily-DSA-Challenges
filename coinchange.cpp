#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1); 
        dp[0] = 0;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount);  
    return 0;
}
