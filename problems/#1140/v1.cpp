class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSums(n);
        suffixSums[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSums[i] = suffixSums[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        int score;
        for (int i = n - 1; i >=0; --i) {
            for (int m = 1; m <= n; ++m) {
                // can take all last piles
                if (i + m * 2 >= n) {
                    dp[i][m] = suffixSums[i];
                } else {
                    for (int x = 1; x <= m * 2; ++x) {
                        score = suffixSums[i] - dp[i + x][max(x, m)];
                        dp[i][m] = max(dp[i][m], score);
                    }
                }
            }
        }
        return dp[0][1];
    }
};