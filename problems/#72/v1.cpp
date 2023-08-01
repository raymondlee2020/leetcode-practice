class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size(), left, top, leftop;
        if (n == 0) {
            return m;
        }
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            leftop = i;
            left = i + 1;
            for (int j = 0; j < n; ++j) {
                top = dp[j];
                dp[j] = word1[i] == word2[j] ? leftop : min(left, min(leftop, top)) + 1;
                left = dp[j];
                leftop = top;
            }
        }
        return dp[n - 1];
    }
};