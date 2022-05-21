#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacii(int n) {
        int F[4] = {0, 1, 1, 2};
        if (n < 4) return F[n];
        for (int i = 3; i <= n; ++i) {
            F[3] = F[0] + F[1] + F[2];
            F[0] = F[1];
            F[1] = F[2];
            F[2] = F[3];
        }
        return F[3];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    for (int i = 0; i < 37; ++i)
        cout << i << ": " << s.tribonacii(i) << endl;
    return 0;
}
