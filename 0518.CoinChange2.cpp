#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto coin = coins.rbegin(); coin != coins.rend(); ++coin) {
            for (int i = 1; i <= amount; ++i)
            {
                if (i - *coin >= 0) {
                    dp[i] += dp[i - *coin];
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int amount = 5;
    vector<int> coins{1, 2, 5};
    cout << s.change(amount, coins) << endl;
    return 0;
}
