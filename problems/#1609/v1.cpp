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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode *prev, *curr;
        int r = 1, d, s;
        q.push(root);
        while (!q.empty()) {
            s = q.size();
            prev = r == 0 ? new TreeNode(1e6 + 1) : new TreeNode(0);
            for (int i = 0; i < s; ++i) {
                curr = q.front(), q.pop();
                if (r == 0) {
                    if (curr->val >= prev->val || curr->val % 2 != r) return false;
                } else {
                    if (curr->val <= prev->val || curr->val % 2 != r) return false;
                }
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
                swap(prev, curr);
            }
            r = (r + 1) % 2;
        }
        return true;
    }
};