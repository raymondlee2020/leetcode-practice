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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr;
        int ret, lvl = 1, maxSum = INT_MIN, tmpSum, width;
        q.push(root);
        while (q.size() > 0) {
            tmpSum = 0;
            width = q.size();
            while (width-- > 0) {
                curr = q.front();
                q.pop();
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
                tmpSum += curr->val;
            }
            if (tmpSum > maxSum) {
                maxSum = tmpSum;
                ret = lvl;
            }
            ++lvl;
        }
        return ret;
    }
};