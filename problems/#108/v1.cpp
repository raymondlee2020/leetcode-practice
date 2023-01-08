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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        return recSortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* recSortedArrayToBST(vector<int>& nums, int l, int r) {
        int mid = (l + r) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        if ((mid - 1) >= l) {
            ret->left = recSortedArrayToBST(nums, l, (mid - 1));
        }
        if ((mid + 1) <= r) {
            ret->right = recSortedArrayToBST(nums, (mid + 1), r);
        }
        return ret;
    }
};