class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pre = 0, cur = 1;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) ++cur;
            else {
                pre = cur;
                cur = 1;
            }

            if (cur >= k && pre >= k || cur/2 >= k) return true;
        }

        return false;
    }
};