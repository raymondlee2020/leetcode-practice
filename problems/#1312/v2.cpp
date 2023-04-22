class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), prev, tmp;
        vector<int> dp(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            prev = 0;
            for (int j = i + 1; j < n; ++j) {
                tmp = dp[j];
                dp[j] = s[i] == s[j] ? prev : (min(tmp, dp[j - 1]) + 1);
                prev = tmp;
            }
        }
        return dp[n - 1];
    }
};