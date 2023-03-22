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
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (head != NULL) {
            if (head->next == NULL || head->val != head->next->val) {
                curr->next = head;
                curr = curr->next;
                head = head->next;
            } else {
                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                head = head->next;
            }
        }
        curr->next = NULL;
        return dummy->next;
    }
};