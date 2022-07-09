#include <bits/stdc++.h>
using namespace std;

/**
 * dp[i][j] => means the maximum length of sub-array which can hold i '1' and j '0' 
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int k = 0; k < strs.size(); ++k) {
            int ones = 0, zeros = 0;
            for (auto x: strs[k]) {
                if (x == '1') ones += 1;
                else zeros += 1;
            }
            auto newDp = dp;
            for (int i = ones; i < m; ++i) {
                for (int j = zeros; j < n; ++j) {
                    newDp[i][j] = min(1 + dp[i - ones][j - zeros], dp[i][j]);
                }
            }
            dp = newDp;
        }
        return dp[m][n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> strs{"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}
