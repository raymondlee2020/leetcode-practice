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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        TreeNode* curr = root1;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (isLeaf(curr)) {
                q.push(curr);
            }
            curr = curr->right;
        }
        curr = root2;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (isLeaf(curr)) {
                if (q.empty() || q.front()->val != curr->val) {
                    return false;
                }
                q.pop();
            }
            curr = curr->right;
        }
        return q.empty();
    }

    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
};