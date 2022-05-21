#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> table;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (table.count(nums[i]) != 0) {
                return true;
            } else {
                table.insert(nums[i]);
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{1,2,3,4};
    cout << (s.containsDuplicate(nums) ? "true" : "false") << endl;
    return 0;
}
