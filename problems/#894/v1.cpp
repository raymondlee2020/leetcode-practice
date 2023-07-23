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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 != 1) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        if (n == 3) {
            return {new TreeNode(0, new TreeNode(0), new TreeNode(0))};
        }
        TreeNode* curr;
        vector<TreeNode*> l, r;
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1] = {new TreeNode(0)};
        dp[3] = {new TreeNode(0, new TreeNode(0), new TreeNode(0))};
        for (int i = 5; i <= n; i += 2) {
            for (int j = 1; j < i; j += 2) {
                l = dp[j], r = dp[i - j - 1];
                for (const auto& lc: l) {
                    for (const auto& rc: r) {
                        curr = new TreeNode(0);
                        curr->left = lc;
                        curr->right = rc;
                        dp[i].push_back(curr);
                    }
                }
            }
        }
        return dp[n];
    }
};