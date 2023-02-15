class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        for (int i = 0; i < n; ++i) {
            if (i - 1 == -1) {
                // max(0, -inf + prices[i])
                dp[i][0] = 0;
                // max(-inf, 0 - prices[i])
                dp[i][1] = -prices[i];
                continue;
            }
            if (i - 2 == -1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                //   dp[i][1] 
                // = max(dp[i - 1][1], dp[-1][0] - prices[i])
                // = max(dp[i - 1][1], 0 - prices[i])
                // = max(dp[i - 1][1], -prices[i])
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};