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
    TreeNode* deleteNode(TreeNode* &root, int key) {
        if (root == NULL) {
            return root;
        } else if (root->val == key) {
            if (root->left == NULL) {
                root = root->right;
            } else {
                rightEdge(root->left)->right = root->right;
                root = root->left;
            }
        } else {
            (root->val > key) ? deleteNode(root->left, key) : deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* rightEdge(TreeNode* root) {
        return (root->right == NULL) ? root : rightEdge(root->right);
    }
};