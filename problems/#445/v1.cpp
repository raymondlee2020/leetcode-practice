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
        ListNode* k1 = l1 = reverse(l1);
        ListNode* k2 = l2 = reverse(l2);
        int tmp, carry = 0;
        while (l1->next != NULL && l2->next != NULL) {
            tmp = l1->val + l2->val + carry;
            l1->val = l2->val = tmp % 10;
            carry = tmp / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        tmp = l1->val + l2->val + carry;
        l1->val = l2->val = tmp % 10;
        carry = tmp / 10;
        if (carry != 0) {
            if (l1->next == NULL && l2->next == NULL) {
                l2->next = new ListNode(carry);
            } else if (l1->next == NULL) {
                l2 = l2->next;
                while (l2->next != NULL && carry != 0) {
                    tmp = l2->val + carry;
                    l2->val = tmp % 10;
                    carry = tmp / 10;
                    l2 = l2->next;
                }
                tmp = l2->val + carry;
                l2->val = tmp % 10;
                carry = tmp / 10;
                if (carry != 0) {
                    l2->next = new ListNode(carry);
                }
                return reverse(k2);
            } else {
                l1 = l1->next;
                while (l1->next != NULL && carry != 0) {
                    tmp = l1->val + carry;
                    l1->val = tmp % 10;
                    carry = tmp / 10;
                    l1 = l1->next;
                }
                tmp = l1->val + carry;
                l1->val = tmp % 10;
                carry = tmp / 10;
                if (carry != 0) {
                    l1->next = new ListNode(carry);
                }
                return reverse(k1);
            }
        }
        return l1->next == NULL ? reverse(k2) : reverse(k1);
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *tmp;
        while (head != NULL) {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};