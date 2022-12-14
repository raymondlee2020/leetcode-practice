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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        ListNode* n;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto l : lists){
            while(l != NULL){
                pq.push(l);
                l = l->next;
            }
        }
        while(!pq.empty()){
            ListNode* n = pq.top();
            n->next = NULL;
            curr->next = n;
            curr = curr->next;
            pq.pop();
        }
        return ret->next;
    }
};