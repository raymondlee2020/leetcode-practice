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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        auto [head, tail] = BST2List(root);
        ListNode* curr = head;
        ListNode* next = head->next;
        while (next != NULL) {
            if (next->val <= curr->val) {
                return false;
            }
            curr = curr->next;
            next = next->next;
        }
        return true;
    }

    pair<ListNode*, ListNode*> BST2List(TreeNode* root) {
        ListNode* rootListNode = new ListNode(root->val);
        ListNode* head = rootListNode;
        ListNode* tail = rootListNode;
        if (root->left != NULL) {
            auto [lhead, ltail] = BST2List(root->left);
            ltail->next = rootListNode;
            head = lhead;
        }
        if (root->right != NULL) {
            auto [rhead, rtail] = BST2List(root->right);
            rootListNode->next = rhead;
            tail = rtail;
        }
        return {head, tail};
    }
};