class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size(), bound = 0, left, top, leftop;
        vector<int> dp(n, 0);
        // init top cases for no chars from s1
        dp[0] = s2[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + s2[i];
        }
        for (int i = 0; i < m; ++i) {
            leftop = bound;
            left = bound + s1[i];
            for (int j = 0; j < n; ++j) {
                top = dp[j];
                dp[j] = min(left + s2[j], top + s1[i]);
                if (s1[i] == s2[j]) {
                    dp[j] = min(dp[j], leftop);
                }
                leftop = top;
                left = dp[j];
            }
            bound += s1[i];
        }
        return dp[n - 1];
    }
};