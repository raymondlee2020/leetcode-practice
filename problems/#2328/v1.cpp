class Solution {
public:
    vector<vector<int> > dp;
    int m, n, MOD;

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (m == 1 && n == 1) {
            return 1;
        }
        MOD = 1e9 + 7;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (dp[i][j] == -1) {
                  ret = (ret + solve(grid, i, j, -1)) % MOD;
                } else {
                  ret = (ret + dp[i][j]) % MOD;
                }
            }
        }
        return ret;
    }

    int solve(vector<vector<int>>& grid, int i, int j, int prev) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] <= prev) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int top = solve(grid, i + 1, j, grid[i][j]);
        int bottom = solve(grid, i - 1, j, grid[i][j]);
        int left = solve(grid, i, j - 1, grid[i][j]);
        int right = solve(grid, i, j + 1, grid[i][j]);
        return dp[i][j] = (1 + top + bottom + left + right) % MOD;
    }
};