#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                res[j] = res[j] + res[j - 1];
            }
            for_each(res.begin(), res.end(), [](auto i) { cout << i << ' '; });
            cout << endl;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int rowIndex = 3;
    vector<int> row = s.getRow(rowIndex);
    for_each(row.begin(), row.end(), [](auto i) { cout << i << ' '; });
    cout << endl;
    return 0;
}
