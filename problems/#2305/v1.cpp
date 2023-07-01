class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size(), mbound = 1 << n;
        vector<int> sum(mbound, 0);
        for (int m = 0; m < mbound; ++m) {
            for (int i = 0; i < n; ++i) {
                if (m & (1 << i)) {
                    sum[m] += cookies[i];
                }
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(mbound, INT_MAX));
        dp[0][0] = 0;
        for (int c = 1; c <= k; ++c) {
            for (int m = 0; m < mbound; ++m) {
                for (int sm = m; sm > 0; sm = (sm - 1) & m) {
                    dp[c][m] = min(dp[c][m], max(sum[sm], dp[c - 1][sm ^ m]));
                }
            }
        }
        return dp[k][mbound - 1];
    }
};