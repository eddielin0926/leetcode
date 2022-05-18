#include <bits/stdc++.h>
using namespace std;

/* Time: O(n) */

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
    bool isBalanced(TreeNode *root)
    {
        if (!root) return true;
        bool balanced = true;
        height(root, &balanced);
        return balanced;
    }
    int height(TreeNode *root, bool *balanced) {
        if (!root) return 0;
        int lefth= height(root->left, balanced);
        int righth = height(root->right, balanced);
        if (abs(lefth - righth) > 1) {
            *balanced = false;
            return - 1;
        }
        return 1 + max(lefth, righth);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode *root = NULL;
    cout << s.isBalanced(root) << endl;
    return 0;
}
