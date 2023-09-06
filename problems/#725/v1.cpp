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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k);
        vector<int> info(4);
        solve(ret, info, head, k, 0);
        return ret;
    }

    void solve(vector<ListNode*>& ret, vector<int>& info, ListNode* curr, int k, int i) {
        if (curr == NULL) {
            info[0] = i / k; // min size of one split
            info[1] = k - (i % k) - 1; // amount of remain split has min size
            info[2] = i  - info[0]; // prev head index in list
            info[3] = k - 1; // split sublist index in return
            if (info[0] == 0) {
                info[1] = 0;
                info[2] = i - 1;
                info[3] = i - 1;
            }
            return;
        }
        solve(ret, info, curr->next, k, i + 1);
        if (i < info[2]) {
            curr->next = NULL;
            info[2] -= info[0];
            if (info[1]-- <= 0) {
                --info[2];
            }
            --info[3];
        }
        if (i == info[2]) {
            ret[info[3]] = curr;
        }
    }
};