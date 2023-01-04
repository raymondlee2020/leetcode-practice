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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre = NULL;
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        while (true) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }
            if (s.empty()) {
                break;
            }
            root = s.top();
            s.pop();
            if (l == NULL) {
                if (pre != NULL && pre->val > root->val) {
                    l = pre;
                    r = root;
                }
            } else {
                if (pre->val > root->val) {
                    r = root;
                    break;
                }
            }
            pre = root;
            root = root->right;
        }
        int tmp = l->val;
        l->val = r->val;
        r->val = tmp;
    }
};