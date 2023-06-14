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
    TreeNode* prev;
    int getMinimumDifference(TreeNode* root) {
        prev = NULL;
        return traverse(root);
    }

    int traverse(TreeNode* curr) {
        int ret = INT_MAX;
        if (curr == NULL) {
            return ret;
        }
        ret = min(ret, traverse(curr->left));
        if (prev != NULL) {
            ret = min(ret, curr->val - prev->val);
        }
        prev = curr;
        return min(ret, traverse(curr->right));
    }
};