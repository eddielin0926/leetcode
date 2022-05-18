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

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return;
        int curMin = INT_MAX;
        _minDepth(root, 1, &curMin);
        return curMin;
    }
    void _minDepth(TreeNode *root, int level, int *curMin) {
        if (level > *curMin) return;
        if (!root->left && !root->right) {
            *curMin = level;
            return;
        }
        if (root->left) _minDepth(root->left, level + 1, curMin);
        if (root->right) _minDepth(root->right, level + 1, curMin);
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode *root = NULL;
    cout << s.minDepth(root) << endl;
    return 0;
}
