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
    ListNode* l;

    int pairSum(ListNode* head) {
        l = head;
        return solve(head);
    }

    int solve(ListNode* r) {
        if (r == NULL) {
            return INT_MIN;
        }
        int ret = solve(r->next);
        ret = max(ret, l->val + r->val);
        l = l->next;
        return ret;
    }
};