class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD = 1e9 + 7, bound = 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            bound = min(bound + i - 1, k);
            for (int j = 1; j <= bound; ++j) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if (j - i >= 0) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};