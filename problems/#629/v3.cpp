class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD = 1e9 + 7, bound = 0;
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[1][0] = 1;
            bound = min(bound + i - 1, k);
            for (int j = 1; j <= bound; ++j) {
                dp[1][j] = (dp[1][j - 1] + dp[0][j]) % MOD;
                if (j - i >= 0) {
                    dp[1][j] = (dp[1][j] - dp[0][j - i] + MOD) % MOD;
                }
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][k];
    }
};