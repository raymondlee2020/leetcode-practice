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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<unsigned int, TreeNode*>> q;
        pair<unsigned int, TreeNode*> l, r, tmp;
        unsigned int s, base, ret = 0;
        q.push({0, root});
        while (!q.empty()) {
            s = q.size();
            l = r = {-1, NULL};
            for (int i = 0; i < s; ++i) {
                tmp = q.front();
                q.pop();
                if (l.second == NULL) {
                    cout << "gl ";
                    l = r = tmp;
                } else {
                    r = tmp;
                }
                if (tmp.second->left != NULL) {
                    q.push({(tmp.first - l.first) * 2, tmp.second->left});
                }
                if (tmp.second->right != NULL) {
                    q.push({(tmp.first - l.first) * 2 + 1, tmp.second->right});
                }
            }
            if (l.second == NULL) {
                break;
            }
            ret = max(ret, (r.first - l.first) + 1);
        }
        return ret;
    }
};