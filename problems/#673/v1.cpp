class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1, 1});
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0;  --j) {
                if (nums[i] <= nums[j]) {
                    continue;
                }
                if (dp[i].first == dp[j].first + 1) {
                    dp[i].second += dp[j].second;
                } else if (dp[i].first < dp[j].first + 1) {
                    dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
        }
        int maxlen = 0, ret;
        for (const auto [len, cnt]: dp) {
            if (len == maxlen) {
                ret += cnt;
            } else if (len > maxlen) {
                maxlen = len;
                ret = cnt;
            }
        }
        return ret;
    }
};