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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *curr = dummy, *cand = head;
        int count = 0;
        while (head != NULL) {
            if (head->val != cand->val) {
                if (count == 1) {
                    curr->next = cand;
                    curr = curr->next; 
                }
                cand = head;
                count = 0;
            }
            ++count;
            head = head->next;
        }
        if (count == 1) {
            curr->next = cand;
            curr = curr->next; 
        }
        curr->next = NULL;
        return dummy->next;
    }
};