class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int MOD = 1e9 + 7, tmp;
        vector<vector<int>> dp(n + 1, vector<int>(7));
        for (int i = 0; i < 6; ++i) {
            dp[1][i] = 1;
        }
        dp[1][6] = 6;
        for (int i = 2; i <= n; ++i) {
            tmp = 0;
            for (int j = 0; j < 6; ++j) {
                dp[i][j] = dp[i - 1][6];
                if (i - rollMax[j] == 1) {
                    --dp[i][j];
                } else if (i - rollMax[j] >= 2) {
                    int invalids = dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j];
                    dp[i][j] = ((dp[i][j] - invalids) % MOD + MOD) % MOD;
                }
                tmp = (tmp + dp[i][j]) % MOD;
            }
            dp[i][6] = tmp;
        }
        return dp[n][6];
    }
};