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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *slow, *fast;
        slow = fast = dummy;
        while (n-- > 0) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next == NULL ? NULL : slow->next->next;
        return dummy->next;
    }
};