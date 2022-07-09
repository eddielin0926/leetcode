#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substr(start, end - start);
    }
    int expandFromMiddle(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l -= 1;
            r += 1;
        }
        return r - l - 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    
    cout << s.longestPalindrome("aba") << endl;
    return 0;
}
