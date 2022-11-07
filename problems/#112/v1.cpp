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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recFindLeafAndCompSum(root, 0, targetSum);
    }
    
    bool recFindLeafAndCompSum(TreeNode* node, int prevSum, int targetSum) {
        if (node == NULL) {
            return false;
        }
        int currSum = prevSum + node->val;
        if (node->left == NULL && node->right == NULL) {
            return currSum == targetSum;
        }
        return recFindLeafAndCompSum(node->left, currSum, targetSum) || recFindLeafAndCompSum(node->right, currSum, targetSum);
    }
};