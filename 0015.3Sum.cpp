#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{-1,0,1,2,-1,-4};
    cout << s.threeSum(nums) << endl;
    return 0;
}
