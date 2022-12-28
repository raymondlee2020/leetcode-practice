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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        auto [min, max] = minMaxValidBST(root);
        return min != NULL;
    }

    pair<TreeNode*, TreeNode*> minMaxValidBST(TreeNode* root) {
        TreeNode* min = root;
        TreeNode* max = root;
        bool valid = true;
        if (root->left != NULL) {
            auto [lMin, lMax] = minMaxValidBST(root->left);
            if (lMin != NULL && root->val > lMax->val) {
                min = lMin;
            } else {
                valid = false;
            }
        }
        if (root->right != NULL) {
            auto [rMin, rMax] = minMaxValidBST(root->right);
            if (rMin != NULL && root->val < rMin->val) {
                max = rMax;
            } else {
                valid = false;
            }
        }
        if (!valid) {
            return {NULL, NULL};
        }
        return {min, max};
    }
};