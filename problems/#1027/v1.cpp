class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        vector<unordered_map<int, int>> dp(n);
        int diff, ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].find(diff) == dp[j].end() ? 2 : dp[j][diff] + 1;
                ret = max(ret, dp[i][diff]);
            }
        }
        return ret;
    }
};