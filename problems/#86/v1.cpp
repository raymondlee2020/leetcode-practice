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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }
        ListNode *lxhead, *lxtail, *gxhead, *gxtail;
        lxhead = new ListNode(0), lxtail = lxhead;
        gxhead = new ListNode(0), gxtail = gxhead;
        while (head != NULL) {
            if (head->val < x) {
                lxtail->next = head;
                lxtail = lxtail->next;
            } else {
                gxtail->next = head;
                gxtail = gxtail->next;
            }
            head = head->next;
        }
        lxtail->next = NULL;
        gxtail->next = NULL;
        if (lxhead->next == NULL) {
            return gxhead->next;
        }
        lxtail->next = gxhead->next;
        return lxhead->next;
    }
};