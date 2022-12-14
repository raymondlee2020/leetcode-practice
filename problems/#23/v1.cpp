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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int n = lists.size();
        ListNode* ret = new ListNode(0);
        ListNode* last = ret;
        ListNode* tmp;
        int pos;
        bool hasNext = true;
        while (hasNext) {
            hasNext = false;
            tmp = NULL;
            // find the min node
            for (int i = 0; i < n; i++) {
                if (lists[i] == NULL) {
                    continue;
                }
                hasNext = true;
                if ((tmp == NULL) || (lists[i]->val < tmp->val)){
                    tmp = lists[i];
                    pos = i;
                }
            }
            if (hasNext) {
                // detach the node from the origin list and attach to the return list
                lists[pos] = lists[pos]->next;
                tmp->next = NULL;
                last->next = tmp;
                last = tmp;
            }
        }
        return ret->next;
    }
};