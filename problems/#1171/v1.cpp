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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m;
        int acc = 0, tacc;
        ListNode *dummy = new ListNode(0, head), *curr = head;
        m[0] = dummy;
        while (curr != NULL) {
            acc += curr->val;
            if (m.find(acc) != m.end()) {
                curr = m[acc]->next, tacc = acc + curr->val;
                while (tacc != acc) m.erase(tacc), curr = curr->next, tacc += curr->val;
                m[acc]->next = curr->next;
            } else {
                m[acc] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};