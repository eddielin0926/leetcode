#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows); 
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int numRows = 5;
    vector<vector<int>> pt = s.generate(numRows);
    for (auto row: pt) {
        for_each(row.begin(), row.end(), [](auto i) { cout << i << ' '; });
        cout << endl;
    }
    return 0;
}
