class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr, prev = 0; // seq of ones
        int ans = 0;

        for (auto num: nums) {
            if (num == 1) ++curr;
            else {
                ans = max(ans, prev + curr);
                prev = curr;
                curr = 0;
            }
        }
        ans = max(ans, prev + curr);

        return ans == nums.size() ? ans - 1 : ans;
    }
};