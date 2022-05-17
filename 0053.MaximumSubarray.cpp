#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> f(nums.size());
        int ans = nums[0];
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            if (ans < f[i])
                ans = f[i];
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{5,4,-1,7,8};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
