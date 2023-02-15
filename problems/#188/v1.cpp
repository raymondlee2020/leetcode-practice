class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int max_k = min(k, n / 2);
        int dp[n][max_k + 1][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= max_k; ++j) {
                if (i - 1 == -1) {
                    // max(0, -inf + prices[i])
                    dp[i][j][0] = 0;
                    // max(-inf, 0 - prices[i])
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                if (j - 1 == -1) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = INT_MIN;
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][max_k][0];
    }
};