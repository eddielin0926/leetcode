#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int mySqrt(int x)
    {
        int a = x;
        int b = 1;
        while (a > b)
        {
            a = (a >> 1) + (b >> 1) + (a & b & 1);
            b = x / a;
        }
        return a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    cout << int(sqrt(INT_MAX)) << endl;
    cout << s.mySqrt(INT_MAX) << endl;
    return 0;
}
