class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool ret = true;
        if (nums[0] > nums[n - 1]) {
            for (int i = 1; i < n; ++i) {
                ret &= nums[i - 1] >= nums[i];
            }
        } else if (nums[0] < nums[n - 1]) {
            for (int i = 1; i < n; ++i) {
                ret &= nums[i - 1] <= nums[i];
            }
        } else {
            for (int i = 1; i < n - 1; ++i) {
                ret &= nums[i] == nums[0];
            }
        }
        return ret;
    }
};