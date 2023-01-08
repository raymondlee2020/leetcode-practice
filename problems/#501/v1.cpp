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
    int last, cnt = 0, max = 0;
    vector<int> ret;
    vector<int> findMode(TreeNode* root) {
        last = root->val;
        helper(root);
        return ret;
    }

    void helper(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        helper(node->left);
        if (node->val == last) {
            cnt++;
        } else {
            last = node->val;
            cnt = 1;
        }
        if (cnt > max) {
            ret = {last};
            max = cnt;
        } else if (cnt == max) {
            ret.push_back(last);
        }
        helper(node->right);
    }
};