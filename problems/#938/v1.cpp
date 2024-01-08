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
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumRange(search(root, low, high), low, high);
    }

    TreeNode* search(TreeNode* node, int low, int high) {
        if (node->val < low) {
            return search(node->right, low, high);
        }
        if (node->val > high) {
            return search(node->left, low, high);
        }
        return node;
    }

    int sumRange(TreeNode* node, int low, int high) {
        if (node == NULL) {
            return 0;
        }
        if (node->val < low) {
            return sumRange(node->right, low, high);
        }
        if (node->val > high) {
            return sumRange(node->left, low, high);
        }
        return sumRange(node->left, low, high) + node->val + sumRange(node->right, low, high);
    }
};