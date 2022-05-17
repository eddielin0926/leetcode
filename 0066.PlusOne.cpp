#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.empty())
        {
            digits.push_back(1);
            return digits;
        }

        digits.back() += 1;
        for (int i = digits.size() - 1; i > 0; --i)
        {
            if (digits[i] < 10) {
                break;
            }
            digits[i] = 0;
            digits[i - 1] += 1;
        }
        if (digits.front() == 10) {
            digits.front() = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> digits{9};
    s.plusOne(digits);
    for (auto i : digits)
        cout << i;
    cout << endl;
    return 0;
}
