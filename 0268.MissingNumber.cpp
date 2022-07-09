#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time: O(nlogn)
    // int missingNumber(vector<int> &nums) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     for (int i = 0; i < n; ++i) {
    //         if (i != nums[i]) {
    //             return i;
    //         }
    //     }
    //     return n;
    // }

    // O(n)
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; ++i) {
            res += (i - nums[i]); 
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    cout << s.missingNumber(nums) << endl;
    return 0;
}
