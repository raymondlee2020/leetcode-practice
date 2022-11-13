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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> cnt;
        int maxFreq = 0;
        recCalcSum(root, cnt, maxFreq);
        vector<int> ans = {};
        for (auto const& [k, v]: cnt) {
            if (v == maxFreq) {
                ans.push_back(k);
            }
        }
        return ans;
    }
    
    int recCalcSum(TreeNode* node, map<int, int>& cnt, int& maxFreq) {
        if (!node) {
            return 0;
        }
        int currSum = node->val + recCalcSum(node->left, cnt, maxFreq) + recCalcSum(node->right, cnt, maxFreq);
        maxFreq = max(maxFreq, ++cnt[currSum]);
        return currSum;
    }
};