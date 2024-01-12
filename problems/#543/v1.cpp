/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        solve(ret, root);
        return ret;
    }

    int solve(int& ret, TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int lmaxdep = solve(ret, node->left), rmaxdep = solve(ret, node->right);
        ret = max(ret, lmaxdep + rmaxdep);
        return max(lmaxdep, rmaxdep) + 1;
    }
};