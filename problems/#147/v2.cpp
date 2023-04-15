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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001);
        ListNode *pv, *curr;
        while (head != NULL) {
            curr = head;
            head = head->next;
            pv = dummy;
            while (pv->next != NULL && pv->next->val < curr->val) {
                pv = pv->next;
            }
            curr->next = pv->next == NULL ? NULL : pv->next;
            pv->next = curr;
        }
        return dummy->next;
    }
};