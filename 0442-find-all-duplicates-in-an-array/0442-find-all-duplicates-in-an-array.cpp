class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;   // since use sign to mark checked position
            if (nums[index] < 0) {
                result.push_back(index + 1);  // duplicate will only appears twice
            } else {
                nums[index] = -nums[index]; // mark as checked
            }
        }
        return result;
    }
};