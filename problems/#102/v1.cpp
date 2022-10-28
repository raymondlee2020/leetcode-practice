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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recTraverseWithOrder(root, 0, ans);
        return ans;
    }
    
    void recTraverseWithOrder(TreeNode* node, int order, vector<vector<int>> &ans) {
        if (node == NULL) {
            return;
        }
        while (ans.size() <= order) {
            ans.push_back({});
        }
        ans[order].push_back(node->val);
        recTraverseWithOrder(node->left, order + 1, ans);
        recTraverseWithOrder(node->right, order + 1, ans);
    }
};