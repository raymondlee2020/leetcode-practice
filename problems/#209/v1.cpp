class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX, n = nums.size(), l = 0, r, tmp = 0;
        for (r = 0; r < n; ++r) {
            tmp += nums[r];
            if (tmp < target) {
                continue;
            }
            ret = min(ret, r - l + 1);
            while (tmp >= target && l <= r) {
                tmp -= nums[l++];
            }
            ret = min(ret, r - l + 2);
        }
        return ret == INT_MAX ? 0 : ret;
    }
};