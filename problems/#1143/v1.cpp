class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = text1[i] == text2[j] ? 1 : 0;
                } else if (i == 0) {
                    dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j - 1];
                } else if (j == 0) {
                    dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
                } else {
                    if (text1[i] == text2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }    
        }
        return dp[m - 1][n - 1];
    }
};