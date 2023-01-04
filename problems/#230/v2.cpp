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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        return BST2Vector(root, v)[k - 1];
    }

    vector<int> BST2Vector(TreeNode* n, vector<int> &v) {
        if (n == NULL) {
            return v;
        }
        BST2Vector(n->left, v);
        v.push_back(n->val);
        BST2Vector(n->right, v);
        return v;
    }
};