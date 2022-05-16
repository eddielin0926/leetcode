#include <bits/stdc++.h>
using namespace std;

/* "ab" pattern: b is larger than a */
/* Sol: Sum all the symbol up, when encounter "ab" pattern, minus 2*a */
/* Time complexity: O(n) */
/* Space complexity: O(1) */

class Solution
{
  public:
    int romanToInt(string s)
    {
        map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        char p = 0;
        int ans = 0;
        for(char c: s) {
            ans += m[c];
            if (p && m[c] > m[p])
                ans -= 2 * m[p];
            p = c;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "MCMXCIV";
    cout << s.romanToInt(str) << endl;
    return 0;
}