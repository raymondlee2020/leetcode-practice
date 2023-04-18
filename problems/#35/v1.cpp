class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid, l = 0, r = nums.size();
        if (target > nums[r - 1]) {
            return r;
        }
        if (target <= nums[l]) {
            return l;
        }
        while ((r - l) > 1) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid;
            } else {
                return mid;
            }
        }
        return r;
    }
};