#include <bits/stdc++.h>
using namespace std;

/* 
 * Time: O(m + n)
 * Space: O(1)
 */

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for_each(nums1.begin(), nums1.end(), [](int x) { cout << x << ' '; });
    cout << endl;
    return 0;
}
