#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        LVR(root, v);
        return v;

    }
    void LVR(TreeNode *root, vector<int> &v) {
        if (!root) return;
        LVR(root->left, v);
        v.push_back(root->val);
        LVR(root->right, v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TreeNode *root = NULL;
    vector<int> v = s.inorderTraversal(root);
    for_each(v.begin(), v.end(), [](auto i) { cout << i << ' '; });
    cout << endl;
    return 0;
}
