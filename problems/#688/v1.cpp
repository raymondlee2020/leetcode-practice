class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;

    double knightProbability(int n, int k, int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= n) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        if (dp.find(r) != dp.end() && dp[r].find(c) != dp[r].end() && dp[r][c].find(k) != dp[r][c].end()) {
            return dp[r][c][k];
        }
        return dp[r][c][k] = (
            knightProbability(n, k - 1, r - 1, c - 2) + knightProbability(n, k - 1, r - 2, c - 1) +
            knightProbability(n, k - 1, r - 1, c + 2) + knightProbability(n, k - 1, r - 2, c + 1) +
            knightProbability(n, k - 1, r + 1, c - 2) + knightProbability(n, k - 1, r + 2, c - 1) +
            knightProbability(n, k - 1, r + 1, c + 2) + knightProbability(n, k - 1, r + 2, c + 1)
        ) / 8;
    }
};