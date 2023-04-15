class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size(), left, top, leftop;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            left = leftop = 0;
            for (int j = 0; j < n; ++j) {
                top = dp[j];
                dp[j] = text1[i] == text2[j] ? (leftop + 1) : max(top, left);
                leftop = top;
                left = dp[j];
            }    
        }
        return dp[n - 1];
    }
};