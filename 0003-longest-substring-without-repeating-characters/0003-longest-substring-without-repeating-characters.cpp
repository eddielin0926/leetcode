class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int result = 0;
        int left = -1;
        unordered_map<int, int> table;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (table.find(ch) != table.end() && table[ch] > left) {
                left = table[ch];
            }
            table[ch] = i;
            result = max(result, i - left);
        }
        return result;
    }
};