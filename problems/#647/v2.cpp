class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ret = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (i == j + 1) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] ? dp[i - 1][j + 1] : 0;
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};