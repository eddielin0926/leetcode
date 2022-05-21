#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(amount * len(coins))
 * Space: O(amount)
 */

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);   // 0 ~ amount, `amount + 1` is greater than maximum possible value
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin: coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
            
        }
        return dp[amount] != (amount + 1) ? dp[amount] : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> coins{1, 2, 5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}
