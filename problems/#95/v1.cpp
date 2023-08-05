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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0] = vector<TreeNode*>();
        if (n == 0) {
            return dp[0];
        }
        dp[0].push_back(NULL);
        TreeNode* tmp;
        for (int s = 1; s <= n; ++s) {
            dp[s] = vector<TreeNode*>();
            for (int rootidx = 1; rootidx <= s; ++rootidx) {
                for (TreeNode* l: dp[rootidx - 1]) {
                    for (TreeNode* r: dp[s - rootidx]) {
                        tmp = new TreeNode(rootidx);
                        tmp->left = l;
                        tmp->right = clone(r, rootidx);
                        dp[s].push_back(tmp);
                    }
                }
            }
        }
        return dp[n];
    }

    TreeNode* clone(TreeNode* root, int offset) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* ret = new TreeNode(root->val + offset); 
        ret->left = clone(root->left, offset);
        ret->right = clone(root->right, offset);
        return ret;
    }
};