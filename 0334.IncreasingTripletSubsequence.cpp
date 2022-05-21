#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(n)
 * Space: O(1)
 */

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        int i = INT_MAX, j = INT_MAX;
        for (auto &num : nums)
        {
            if (num <= i) {
                i = num;
            }
            else if (num <= j) {
                j = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{2, 1, 5, 0, 4, 6};
    cout << (s.increasingTriplet(nums) ? "true" : "false") << endl;
    return 0;
}
