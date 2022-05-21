#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numMap;
        vector<int> ans(2);

        for (int i = 0; i < nums.size(); ++i) {
            if (numMap.find(nums[i]) != numMap.end()) {
                ans[0] = numMap[nums[i]];
                ans[1] = i;
                return ans;
            } else {
                numMap[target - nums[i]] = i;
            }
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{2,7,11,15};
    int target = 9;
    cout << s.twoSum(nums, target) << endl;
    return 0;
}
