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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *pv = head;
        int step = 0;
        while (pv->next != NULL) {
            ++step;
            pv = pv->next;
        }
        ++step;
        pv->next = head;
        step = step - (k % step);
        while (step-- > 0) {
            pv = pv->next;
        }
        head = pv->next;
        pv->next = NULL;
        return head;
    }
};