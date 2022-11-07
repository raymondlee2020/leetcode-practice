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
    int sumNumbers(TreeNode* root) {
        return recSumNumbers(root, 0);
    }
    
    int recSumNumbers(TreeNode* node, int prevNum) {
        if (node == NULL) {
            return 0;
        }
        int currNum = prevNum * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            return currNum;
        }
        return recSumNumbers(node->left, currNum) + recSumNumbers(node->right, currNum);
    }
};