class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> prefix(nums.begin(), nums.end());
        vector<int> postfix(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            prefix[i] *= prefix[i - 1];
        }
        for (int i = n - 2; i > 0; i--) {
            postfix[i] *= postfix[i + 1];
        }
        vector<int> result;
        result.push_back(postfix[1]);
        for (int i = 1; i < n - 1; i++) {
            result.push_back(prefix[i - 1] * postfix[i + 1]);
        }
        result.push_back(prefix[n - 2]);
        return result;
    }
};