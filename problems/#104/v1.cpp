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
    int maxDepth(TreeNode* root) {
        return traverse(0, root);
    }

    int traverse(int depth, TreeNode* node) {
        if (node == NULL) {
            return depth;
        }
        ++depth;
        return max(traverse(depth, node->left), traverse(depth, node->right));
    }
};