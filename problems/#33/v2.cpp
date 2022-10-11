class Solution {
public:
    int search(vector<int>& nums, int target) {
        return recSearch(nums, 0, nums.size() - 1, target);
    }
    
    int recSearch(vector<int>& nums, int start, int end, int target) {
        int pv = (start + end) / 2;
        if (nums[pv] == target) {
            return pv;
        }
        if (start > end || start == end) {
            return -1;
        }
        if (nums[pv] >= nums[start]) {
            if (nums[start] <= target && nums[pv] > target) {
                return recSearch(nums, start, pv - 1, target);
            } else {
                return recSearch(nums, pv + 1, end, target);
            }
        } else {
            if (nums[pv] < target && nums[end] >= target) {
                return recSearch(nums, pv + 1, end, target);
            } else {
                return recSearch(nums, start, pv - 1, target);
            }
        }
    }
};