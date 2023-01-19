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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        // get half node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* tmp;
        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        slow->next = NULL;
        // merge list
        ListNode* head1 = head;
        ListNode* head2 = prev;
        while (head2) {
            tmp = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = tmp;
        }
    }
};