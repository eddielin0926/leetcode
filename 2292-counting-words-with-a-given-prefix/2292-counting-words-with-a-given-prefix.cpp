class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int prefixLength = pref.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool isPrefix = true;
            int wordLength = words[i].size();
            if (wordLength < prefixLength) {
                continue;
            }
            for (int j = 0; j < prefixLength; j++) {
                if (words[i][j] != pref[j]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                count += 1;
            }
        }
        return count;
    }
};