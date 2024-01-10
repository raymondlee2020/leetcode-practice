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
    int amountOfTime(TreeNode* root, int start) {
        int ret = 0;
        propagate(ret, root, start);
        return ret;
    }

    pair<bool, int> propagate(int& ret, TreeNode* node, int start) {
        if (node == NULL) {
            return {false, 0};
        }
        pair<bool, int> lres = propagate(ret, node->left, start), rres = propagate(ret, node->right, start);
        if (node->val == start) {
            ret = max(ret, max(lres.second, rres.second));
            return {true, 0};
        }
        if (lres.first) {
            ret = max(ret, 1 + lres.second + rres.second);
            return {true, 1 + lres.second};
        } else if (rres.first) {
            ret = max(ret, 1 + lres.second + rres.second);
            return {true, 1 + rres.second};
        }
        return {false, 1 + max(lres.second, rres.second)};
    }
};