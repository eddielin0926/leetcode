#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();
        int l, r;
        for (int i = 0; i < n; ++i) {
            l = r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                res += 1;
                l -= 1;
                r += 1;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                res += 1;
                l -= 1;
                r += 1;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    cout << s.countSubstrings("abc") << endl;
    return 0;
}
