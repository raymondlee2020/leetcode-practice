class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        if (nums[l] >= 0 && nums[r] >= 0) {
            for (int i = 0; i < n; ++i) {
                nums[i] = pow(nums[i], 2);
            }
            return nums;
        }
        if (nums[l] < 0 && nums[r] < 0) {
            while (l < r) {
                nums[l] = pow(nums[l], 2);
                nums[r] = pow(nums[r], 2);
                swap(nums[l++], nums[r--]);
            }
            if (l == r) {
                nums[l] = pow(nums[l], 2);
            }
            return nums;
        }
        vector<int> ret(n);
        int pv = r;
        nums[l] = pow(nums[l], 2);
        nums[r] = pow(nums[r], 2);
        while (l < r) {
            if (nums[l] > nums[r]) {
                ret[pv--] = nums[l++];
                nums[l] = pow(nums[l], 2);
            } else {
                ret[pv--] = nums[r--];
                nums[r] = pow(nums[r], 2);
            }
        }
        if (l == r) {
            ret[0] = pow(nums[l], 0.5);
        }
        return ret;
    }
};