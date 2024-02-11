class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), nidx;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[0][j][k] = 0;
                    for (int x = max(0, j - 1); x < min(n, j + 2); ++x) {
                        for (int y = max(0, k - 1); y < min(n, k + 2); ++y) {
                            dp[0][j][k] = max(dp[0][j][k], dp[1][x][y]);
                        }
                    }
                    dp[0][j][k] += j == k ? grid[i][j] : (grid[i][j] + grid[i][k]);
                }
            }
            swap(dp[0], dp[1]);
        }
        return dp[1][0][n - 1];
    }
};