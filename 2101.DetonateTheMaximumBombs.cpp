#include <bits/stdc++.h>
using namespace std;

/**
 * Time: O(N^3)
 */

class Solution
{
    vector<int> next[100];
  public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int res = 0;
        int n = bombs.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (dx * dx + dy * dy <= r * r)
                {
                    next[i].push_back(j);
                }
            }
        }

        for (int start = 0; start < n; ++start)
        {
            queue<int> q;
            q.push(start);
            vector<int> visited(n);
            visited[start] = 1;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int i : next[cur])
                {
                    if (visited[i])
                        continue;
                    q.push(i);
                    visited[i] = 1;
                }

                int count = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (visited[i])
                        ++count;
                }
                res = max(res, count);
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> bombs{{1, 1, 5}, {10, 10, 5}};
    cout << s.maximumDetonation(bombs) << endl;
    return 0;
}
