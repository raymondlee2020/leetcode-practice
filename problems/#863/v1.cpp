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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        findPath(path, root, target);
        vector<int> ret;
        int dis, n = path.size();
        for (int i = 0; i < n; ++i) {
            dis = k - i;
            if (dis < 0) {
                break;
            } else if (dis == 0) {
                ret.push_back(path[i]->val);
            } else {
                solve(ret, path[i], dis);
            }
        }
        return ret;
    }

    bool findPath(vector<TreeNode*>& path, TreeNode* node, TreeNode* target) {
        if (node == NULL) {
            return false;
        }
        if (node == target) {
            path.push_back(node);
            return true;
        }
        if (findPath(path, node->left, target)) {
            path.push_back(node);
            node->left = NULL;
            return true;
        }
        if (findPath(path, node->right, target)) {
            path.push_back(node);
            node->right = NULL;
            return true;
        }
        return false;
    }

    void solve(vector<int>& ret, TreeNode* node, int dis) {
        if (node == NULL) {
            return;
        }
        if (dis == 0) {
            ret.push_back(node->val);
        }
        --dis;
        solve(ret, node->left, dis);
        solve(ret, node->right, dis);
    }
};