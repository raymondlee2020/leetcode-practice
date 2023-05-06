class Solution {
public:
    int n, MOD;

    int numSubseq(vector<int>& nums, int target) {
        n = nums.size(), MOD = 1000000007;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = (pows[i - 1] * 2) % MOD;
        }
        sort(nums.begin(), nums.end());
        int ret = 0, l = 0, r = n - 1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                --r;
            } else {
                ret = (ret + pows[r - l++]) % MOD;
            }
        }
        return ret;
    }
};