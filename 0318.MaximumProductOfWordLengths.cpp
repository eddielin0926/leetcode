#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool hasCom = false;
                for (int k = 0; k < words[i].length(); ++k) {
                    if (words[j].find(words[i][k]) != string::npos) {
                        hasCom = true;
                        break;
                    }
                }
                if(!hasCom) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> words{"a","aa","aaa","aaaa"};
    cout << s.maxProduct(words) << endl;
    return 0;
}
