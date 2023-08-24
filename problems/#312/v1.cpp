class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> exnums(nums.size() + 2);
        int n = 1;
        for (int num: nums) {
            if (num > 0) {
                exnums[n++] = num;
            }
        }
        exnums[0] = exnums[n++] = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int r;
        for (int d = 2; d < n; ++d) {
            for (int l = 0; l < n - d; ++l) {
                r = l + d;
                for (int i = l + 1; i < r; ++i) {
                    dp[l][r] = max(dp[l][r], exnums[l] * exnums[i] * exnums[r] + dp[l][i] + dp[i][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};