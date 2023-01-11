class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid, l = 0, r = nums.size() - 1;
        if (target < nums[l] || target > nums[r]) {
            return -1;
        }
        while (l != r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }          
        }
        if (target != nums[l]) {
            return -1;
        }
        return l;
    }
};