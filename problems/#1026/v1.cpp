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
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }

    int solve(TreeNode* node, int minans, int maxans) {
        if (node == NULL) {
            return INT_MIN;
        }
        int ret = max(abs(node->val - minans), abs(node->val - maxans));
        minans = min(minans, node->val);
        maxans = max(maxans, node->val);
        ret = max(ret, solve(node->left, minans, maxans));
        ret = max(ret, solve(node->right, minans, maxans));
        return ret;
    }
};