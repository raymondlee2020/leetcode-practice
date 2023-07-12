class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zero = -1, nonzero = -1;
        while (++zero < n && nums[zero] != 0) {}
        nonzero = zero;
        while (++nonzero < n && nums[nonzero] == 0) {}
        while (zero != n && nonzero != n) {
            swap(nums[zero], nums[nonzero]);
            while (++zero < n && nums[zero] != 0) {}
            while (++nonzero < n && nums[nonzero] == 0) {}
        }
    }
};