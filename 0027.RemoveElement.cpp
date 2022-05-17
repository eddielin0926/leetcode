#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(remove_if(nums.begin(), nums.end(), [val](int x) { return x == val; }), nums.end());
        return nums.size();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}
