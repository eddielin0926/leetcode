#include <bits/stdc++.h>
using namespace std;

/* Sol: Sum all the symbol up, when encounter "ab" pattern, minus 2*a */
/* Time complexity: O(n) */
/* Space complexity: O(1) */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];
        for(auto it = strs.begin() + 1; it != strs.end(); ++it) {
            while(it->find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
            }
        }

        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}