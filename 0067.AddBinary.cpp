#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        string ans;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += (a[i--] - '0');
            if (j >= 0)
                sum += (b[j--] - '0');
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }
        if (carry != 0)
            ans = "1" + ans;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string a = "11", b = "1";
    cout << s.addBinary(a, b) << endl;
    return 0;
}
