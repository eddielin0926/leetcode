class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (auto &num: nums) {
            if (set.find(num - 1) == set.end()) {
                int length = 0;
                while (set.find(num + length) != set.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};