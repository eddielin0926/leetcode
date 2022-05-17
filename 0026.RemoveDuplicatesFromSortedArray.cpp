#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        int i = 0;
        for (auto it = nums.begin(); it != nums.end() - 1;) {
            if (*it == *(it + 1)) nums.erase(it + 1);
            else ++it;
        }
        return nums.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{1, 2};
    cout << s.removeDuplicates(nums) << endl;

    return 0;
}
