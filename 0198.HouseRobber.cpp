#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;

        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i + 1] = max(dp[i], nums[i] + dp[i - 1]);
        }

        return dp[n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{2,7,9,3,1};
    cout << s.rob(nums) << endl;
    return 0;
}
