class Solution {
public:
    int n;
    vector<vector<vector<vector<int>>>> dp;

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<vector<int>>>>(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        return max(0, solve(grid, 0, 0, 0, 0));
    }

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        if (r1 == n || c1 == n || r2 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (dp[r1][c1][r2][c2] != -1) {
            return dp[r1][c1][r2][c2];
        }
        if ((r1 == n - 1 && c1 == n - 1) || (r2 == n - 1 && c2 == n - 1)) {
            return grid[n - 1][n - 1];
        }
        int base = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2], ret = INT_MIN;
        ret = max(ret, base + solve(grid, r1 + 1, c1, r2 + 1, c2));
        ret = max(ret, base + solve(grid, r1 + 1, c1, r2, c2 + 1));
        ret = max(ret, base + solve(grid, r1, c1 + 1, r2 + 1, c2));
        ret = max(ret, base + solve(grid, r1, c1 + 1, r2, c2 + 1));
        return dp[r1][c1][r2][c2] = ret;
    }
};