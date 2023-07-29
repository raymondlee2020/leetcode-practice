class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) {
            return 1;
        }
        n = (n + 24) / 25;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return solve(dp, n, n);
    }

    double solve(vector<vector<double>>& dp, int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1;
        }
        if (b <= 0) {
            return 0;
        }
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        return dp[a][b] = 0.25 * (solve(dp, a - 4, b) + solve(dp, a - 3, b - 1) + solve(dp, a - 2, b - 2) + solve(dp, a - 1, b - 3));
    }
};