class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int s = nums.size();
        for (int i = (s / 2) + 1;i >= 0;i--) {
            heapify(nums, s, i);
        }
        for (int i = s - 1;i >= 0;i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
    
    void heapify(vector<int>& nums, int bound, int parent) {
        int l = parent * 2 + 1;
        int r = parent * 2 + 2;
        int max = parent;
        if (l < bound && nums[l] > nums[max]) {
            max = l;
        }
        if (r < bound && nums[r] > nums[max]) {
            max = r;
        }
        if (max != parent) {
            swap(nums[max], nums[parent]);
            heapify(nums, bound, max);
        }
    }
};