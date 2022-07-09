#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long lmass = mass;
        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (lmass < asteroids[i]) {
                return false;
            }
            lmass += asteroids[i];
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int mass = 5;
    vector<int> asteroids{4,9,23,4};
    cout << (s.asteroidsDestroyed(mass, asteroids) ? "true" : "false") << endl;
    return 0;
}
