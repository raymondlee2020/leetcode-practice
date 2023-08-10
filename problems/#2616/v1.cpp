class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size(), lo = 0, hi = nums[n - 1] - nums[0], mid, pcnt;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            pcnt = 0;
            for (int i = 1; i < n; ++i) {
                if (nums[i] - nums[i - 1] <= mid) {
                    ++pcnt, ++i;
                }
            }
            if (pcnt >= p) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};