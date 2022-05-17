#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int f[3] = {1, 2, 3};
        for (int i = 2; i < n; ++i) {
            f[2] = f[1] + f[0];
            f[0] = f[1];
            f[1] = f[2];
        }
        return f[2];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int n = 45;
    cout << s.climbStairs(n) << endl;
    return 0;
}
