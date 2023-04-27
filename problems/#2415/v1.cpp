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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }

    void dfs(TreeNode* l, TreeNode* r, int level) {
        if (l == NULL) {
            return;
        }
        if (level % 2 == 1) {
            swap(l->val, r->val);
        }
        dfs(l->left, r->right, level + 1);
        dfs(l->right, r->left, level + 1);
    }
};