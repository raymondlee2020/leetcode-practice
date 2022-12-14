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
        if (n == 0) {
            return NULL;
        }
        return divide(lists, 0, n - 1);
    }

    ListNode* divide(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = (start + end) / 2;
        ListNode* l1 = divide(lists, start, mid);
        ListNode* l2 = divide(lists, mid + 1, end);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};