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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = l1->val + l2->val;
        bool stop = (l1->next == NULL) && (l2->next == NULL);
        ListNode* n1 = l1->next == NULL ? new ListNode(0) : l1->next;
        ListNode* n2 = l2->next == NULL ? new ListNode(0) : l2->next;
        if (s > 9) {
            l1->val = s % 10;
            n1->val += 1;
            stop = false;
        } else {
            l1->val = s;
        }
        if (!stop) {
            l1->next = n1;
            addTwoNumbers(n1, n2);
        }
        return l1;
    }
};