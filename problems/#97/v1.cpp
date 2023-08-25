class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = true;
                } else if (i == 0) {
                    dp[0][j] = (dp[0][j - 1] && s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[i][0] = (dp[i - 1][0] && s1[i - 1] == s3[i - 1]);
                } else {
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};