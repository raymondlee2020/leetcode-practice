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
    TreeNode* curr;

    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* ret = increasingBST(root->left);
        if (curr == NULL) {
            ret = curr = root;
        } else {
            curr->right = root;
            curr = root;
            curr->left = NULL;
        }
        increasingBST(root->right);
        return ret;
    }
};