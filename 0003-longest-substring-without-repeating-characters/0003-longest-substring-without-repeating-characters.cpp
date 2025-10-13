class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int result = 0;
        int left = -1;
        unordered_map<char, int> table;

        for (int i = 0; i < n; i++) {
            if (table.find(s[i]) != table.end() && table[s[i]] > left) {
                left = table[s[i]];
            }
            result = max(result, i - left);
            table[s[i]] = i;
        }

        return result;
    }
};