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
        ListNode *a, *b;
        a = b = head;
        for (int i = 0; i < k; i++) {
            if (b == NULL) {
                return head; 
            }
            b = b->next;
        }
        ListNode *newHead = recursiveReverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }

    ListNode* recursiveReverse(ListNode* head, ListNode* tail) {
        if (head->next == tail) {
            return head;
        }
        ListNode* last = recursiveReverse(head->next, tail);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};