#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;

        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (j >= 0 && s[j] != ' ' )
        {
            --j;
        }
        return i - j;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string str = "luffy is still joyboy";
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}
