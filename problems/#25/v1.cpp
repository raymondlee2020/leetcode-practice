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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(0, head);
        head = dummy;
        while (head != NULL) {
            ListNode *a, *b;
            a = b = head->next;
            for (int i = 0; i < k; ++i) {
                if (b == NULL) {
                    return dummy->next;
                }
                b = b->next;
            }
            head->next = iterativeReverse(a, b);
            head = a;
        }
        return dummy->next;
    }

    ListNode* iterativeReverse(ListNode* head, ListNode* tail) {
        ListNode *next, *prev = tail;
        while (head != tail) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};