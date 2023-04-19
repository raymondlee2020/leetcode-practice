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
    int longestZigZag(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(getLongestZigZag(root->left, 0, 'l'), getLongestZigZag(root->right, 0, 'r'));
    }

    int getLongestZigZag(TreeNode* node, int curr, char prevd) {
        if (node == NULL) {
            return curr;
        }
        int ret = ++curr;
        if (prevd == 'l') {
            ret = max(getLongestZigZag(node->left, 0, 'l'), getLongestZigZag(node->right, curr, 'r'));
        } else {
            ret = max(getLongestZigZag(node->left, curr, 'l'), getLongestZigZag(node->right, 0, 'r'));
        }
        return ret;
    }
};