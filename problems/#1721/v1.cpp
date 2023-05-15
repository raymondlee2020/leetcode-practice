/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *slow = head, *fast = head, *memo;
        while (--k > 0) {
            fast = fast->next;
        }
        memo = fast;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val, memo->val);
        return head;
    }
};