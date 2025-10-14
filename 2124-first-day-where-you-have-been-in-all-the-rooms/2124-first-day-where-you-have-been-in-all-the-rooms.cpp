class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int MOD = 1e9 + 7;
        int n = nextVisit.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n - 1; ++i) {
            dp[i + 1] = (2 * dp[i] - dp[nextVisit[i]] + 2 + MOD) % MOD;
        }

        return dp[n - 1];
    }
};