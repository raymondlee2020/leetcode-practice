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
        unordered_map<TreeNode*, vector<TreeNode*>> ancs;
        queue<TreeNode*> nq;
        TreeNode* curr;
        ancs[root] = {root};
        nq.push(root);
        while (ancs.find(p) == ancs.end() || ancs.find(q) == ancs.end()) {
            curr = nq.front();
            nq.pop();
            if (curr->left != NULL) {
                nq.push(curr->left);
                ancs[curr->left] = vector<TreeNode*>(ancs[curr].begin(), ancs[curr].end());
                ancs[curr->left].push_back(curr->left);
            }
            if (curr->right != NULL) {
                nq.push(curr->right);
                ancs[curr->right] = vector<TreeNode*>(ancs[curr].begin(), ancs[curr].end());
                ancs[curr->right].push_back(curr->right);
            }
        }
        TreeNode* ret = NULL;
        int steps = min(ancs[p].size(), ancs[q].size());
        for (int i = 0; i < steps; ++i) {
            if (ancs[p][i] != ancs[q][i]) {
                break;
            }
            ret = ancs[p][i];
        }
        return ret;
    }
};