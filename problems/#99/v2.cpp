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
    TreeNode* l = NULL;
    TreeNode* lnext = NULL;
    TreeNode* r = NULL;
    TreeNode* pre = NULL;
    void recoverTree(TreeNode* root) {
        inOrderTrav(root);
        if (r != NULL) {
            swap(l->val, r->val);
        } else {
            swap(l->val , lnext->val);
        }
    }

    void inOrderTrav(TreeNode* n){
        if (n == NULL) {
            return;
        }
        inOrderTrav(n->left);
        if (pre != NULL && pre->val > n->val) {
            if (l == NULL) {
                l = pre;
                lnext = n;
            } else {
                r = n;
            }
        }
        pre = n;
        inOrderTrav(n->right);
    }
};