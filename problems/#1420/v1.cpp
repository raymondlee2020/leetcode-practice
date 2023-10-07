class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));
        for (int i = 1; i <= m; ++i) {
            dp[1][i][1] = 1;
        }
        long long tmp;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
                for (int c = 1; c <= k; ++c) {
                    tmp = 0;
                    tmp = (tmp + dp[a - 1][b][c] * b) % MOD;
                    for (int i = 1; i < b; ++i) {
                        tmp = (tmp + dp[a - 1][i][c - 1]) % MOD;
                    }
                    dp[a][b][c] = (dp[a][b][c] + tmp) % MOD;
                }
            }
        }
        long long ret = 0;
        for (int i = k; i <= m; ++i) {
            ret = (ret + dp[n][i][k]) % MOD;
        }
        return int(ret);
    }
};