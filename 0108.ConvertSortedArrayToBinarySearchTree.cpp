#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;

        const size_t half_size = nums.size() / 2;

        TreeNode *root = new TreeNode(nums[half_size]);

        if (half_size == 0)
            return root;

        vector<int> left(nums.begin(), nums.begin() + half_size);
        vector<int> right(nums.begin() + half_size + 1, nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> v{-10, -3, 0, 5, 9};
    s.sortedArrayToBST(v);
    return 0;
}
