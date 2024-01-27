class Solution {
public:
    int kInversePairs(int n, int k) {
        int MOD = 1e9 + 7, bound = 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            bound = min(bound + i - 1, k);
            for (int j = 1; j <= bound; ++j) {
                for (int l = max(j - (i - 1), 0); l <= j; ++l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};