class Solution {
public:
    int MOD;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(dp, m, n, maxMove, startRow, startColumn);
    }

    int solve(vector<vector<vector<int>>>& dp, int m, int n, int move, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n) {
            return 1;
        }
        if (move == 0) {
            return 0;
        }
        if (dp[i][j][move] != -1) {
            return dp[i][j][move];
        }
        int ret = 0;
        ret = (ret + solve(dp, m, n, move - 1, i + 1, j)) % MOD;
        ret = (ret + solve(dp, m, n, move - 1, i - 1, j)) % MOD;
        ret = (ret + solve(dp, m, n, move - 1, i, j + 1)) % MOD;
        ret = (ret + solve(dp, m, n, move - 1, i, j - 1)) % MOD;
        return dp[i][j][move] = ret;
    }
};