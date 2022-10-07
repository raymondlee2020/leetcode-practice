class Solution {
public:
    int findMin(vector<int>& nums) {
        return recFindMin(nums, 0, nums.size() - 1);
    }
    
    int recFindMin(vector<int>& nums, int start, int end) {
        if (nums[start] <= nums[end]) {
            return nums[start];
        }
        if ((end - start) == 1) {
            return min(nums[start], nums[end]);
        }
        int pv = (start + end) / 2;
        if (nums[pv] > nums[end]) {
            return recFindMin(nums, pv, end);
        } else {
            return recFindMin(nums, start, pv);
        }
    }
};