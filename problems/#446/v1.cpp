class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0, n = nums.size(), cnt;
        long diff;
        vector<unordered_map<long, int>> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                diff = (long) nums[i] - nums[j];
                cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                ret += cnt;
            }
        }
        return ret;
    }
};