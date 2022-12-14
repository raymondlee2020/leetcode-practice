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
        ListNode* curr;
        ListNode* ptr;
        ListNode* tmp;
        ListNode* ret = new ListNode(0);
        while (head != NULL) {
            // detach the node
            curr = head;
            head = head->next;
            curr->next = NULL;
            // insert the node
            ptr = ret;
            while ((tmp = ptr->next) != NULL) {
                if (curr->val <= tmp->val) {
                    break;
                }
                ptr = ptr->next;
            }
            ptr->next = curr;
            curr->next = tmp;
        }
        return ret->next;
    }
};