class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (index >= 0 && index < nums.size()) {
                if (nums[index] == 0) {
                    nums[index] = -(nums.size()+1);
                } else {
                    nums[index] = -abs(nums[index]);
                }
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] >= 0) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};