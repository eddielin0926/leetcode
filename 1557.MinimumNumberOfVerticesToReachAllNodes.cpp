#include <bits/stdc++.h>
using namespace std;

/**
 * Sol: We only need to find the vertices that have no path to it.
 */

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> counts(n);
        for(vector<int> edge: edges) {
            counts[edge[1]] += 1;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (counts[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> edges{{0,1},{0,2},{2,5},{3,4},{4,2}};
    vector<int> res = s.findSmallestSetOfVertices(edges.size(), edges);
    for_each(res.begin(), res.end(), [](auto i) { cout << i << ' '; });
    cout << endl;
    return 0;
}
