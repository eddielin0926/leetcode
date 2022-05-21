#include <bits/stdc++.h>
using namespace std;

/**
 * Sol: Fast Doubling
 *   F(2k) = F(k)[2F(k+1) - F(k)]
 *   F(2k+1) = F(k+1)^2+F(k)^2
 */

class Solution
{
  public:
    int fib(int n)
    {
        if (n == 0) return 0;
        int a = 0, b = 1;
        // ((sizeof(n) * 8) - __builtin_clz(n)): highest 1 position
        for (int i = ((sizeof(n) * 8) - __builtin_clz(n)); i > 0; i--)
        {
            // a => F(k)
            // b => F(k+1)
            long long t1 = a * (2 * b - a);     // F(2k)
            long long t2 = (b * b) + (a * a);   // F(2k + 1)
            a = t1;
            b = t2;
            if (n & ((1 << i) >> 1))    // check the ith bit is 1 or 0 
            {
                t1 = a + b;
                a = b;
                b = t1;
            }
        }
        return a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;

    cout << s.fib(30) << endl;
    return 0;
}
