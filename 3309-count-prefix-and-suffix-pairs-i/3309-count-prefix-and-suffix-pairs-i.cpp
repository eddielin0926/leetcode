class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        if (n < 2) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        if (n1 > n2) {
            return false;
        }

        for (int i = 0; i < n1; i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
            if (str1[n1 - 1 - i] != str2[n2 - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};