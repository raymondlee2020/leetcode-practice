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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int s, ret = 0;
        queue<TreeNode*> q;
        TreeNode* curr;
        q.push(root);
        while (!q.empty()) {
            ++ret;
            s = q.size();
            while (s-- > 0) {
                curr = q.front();
                q.pop();
                if (curr == NULL) {
                    continue;
                }
                if (curr->left == NULL && curr->right == NULL) {
                    return ret;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ret;
    }
};