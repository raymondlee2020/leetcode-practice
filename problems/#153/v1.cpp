class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (true) {
            if ((end - start) == 1) {
                return min(nums[start], nums[end]);
            }
            if (nums[start] <= nums[end]) {
                return nums[start];
            }
            int pv = (start + end) / 2;
            if (nums[pv] > nums[end]) {
                start = pv;
            } else {
                end = pv;
            }
        }
    }
};