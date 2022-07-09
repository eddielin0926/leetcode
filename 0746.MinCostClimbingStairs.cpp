#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int minCostClimbStairs(vector<int> &cost)
    {
        int n = cost.size();
        int step1 = 0, step2 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int curStep = cost[i] + min(step1, step2);
            step2 = step1;
            step1 = curStep;
        }
        return min(step1, step2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s.minCostClimbStairs(cost) << endl;
    return 0;
}
