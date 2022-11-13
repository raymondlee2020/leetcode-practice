/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> tmp;
        map<TreeNode*, TreeNode*> parent;
        tmp.push(root);
        parent[root] = NULL;
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = tmp.top();
            tmp.pop();
            if (node->left != NULL) {
                tmp.push(node->left);
                parent[node->left] = node;
            }
            if (node->right != NULL) {
                tmp.push(node->right);
                parent[node->right] = node;
            }
        }
        set<TreeNode*> ancs;
        while (p != NULL) {
            ancs.insert(p);
            p = parent[p];
        }
        while (ancs.find(q) == ancs.end()) {
            q = parent[q];
        }
        return q;
    }
};