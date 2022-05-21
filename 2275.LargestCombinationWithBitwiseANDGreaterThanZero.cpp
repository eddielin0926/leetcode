#include <bits/stdc++.h>
using namespace std;

/**
 * Sol: We only need to find the bit position with maximum number of 1.
 * Consider two position p1 and p2 with m1 and m2 amount of 1. We cannot 
 * find a m greater than max(m1, m2) because the AND result of m1 + 1 is 0 
 * so does m2.
 */

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int res = 0;
        for (int i = 0; i < 24; ++i) { // 1 <= candidates[i] <= 10^7, no need for 32 bits
            int count = 0;
            for (int cur: candidates) {
                if (1 & (cur >> i)) {
                    count += 1;
                }
            }
            res = max(res, count);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> candidates = {16,17,71,62,12,24,14};
    cout << s.largestCombination(candidates) << endl;
    return 0;
}
