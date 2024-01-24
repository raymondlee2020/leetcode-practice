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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ret = 0;
        vector<int> cnt(10, 0);
        solve(ret, cnt, root);
        return ret;
    }

    void solve(int& ret, vector<int>& cnt, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        ++cnt[node->val];
        if (node->left == NULL && node->right == NULL) {
            int odd = 0;
            for (const auto& n: cnt) {
                if (n % 2 == 1) {
                    ++odd;
                }
            }
            if (odd <= 1) {
                ++ret;
            }
        } else {
            solve(ret, cnt, node->left);
            solve(ret, cnt, node->right);
        }
        --cnt[node->val];
    }
};