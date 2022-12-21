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

    struct MinHeap {
        int size;
        vector<int> nums;
        MinHeap(vector<int> nums): nums(nums) {
            size = nums.size();
            for (int i = (size / 2) + 1; i >= 0; i--) {
                heapify(i);
            }
        }
        void heapify(int pos) {
            int l = 2 * pos + 1;
            int r = 2 * pos + 2;
            int min = pos;
            if (l < size && nums[l] < nums[min]) {
                min = l;
            }
            if (r < size && nums[r] < nums[min]) {
                min = r;
            }
            if (min != pos) {
                swap(nums[pos], nums[min]);
                heapify(min);
            }
        }
        int pop() {
            int ret = nums[0];
            swap(nums[0], nums[size - 1]);
            nums.pop_back();
            size--;
            heapify(0);
            return ret;
        }
    };

    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        MinHeap heap = MinHeap(nums);
        ListNode* ret = new ListNode(0);
        ListNode* curr = ret;
        while (heap.size > 0) {
            curr->next = new ListNode(heap.pop());
            curr = curr->next;
        }
        return ret->next;
    }
};