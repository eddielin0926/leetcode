class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        int odd = 0;
        int left = 0, middle = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2) {
                odd += 1;
            }

            while (odd > k) {
                if (nums[left] % 2) {
                    odd -= 1;
                }
                left += 1;
            }
            middle = left;

            if (odd == k) {
                while (nums[middle] % 2 == 0) {
                    middle += 1;
                }
                result += (middle - left) + 1;
            }
        }

        return result;
    }
};