class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size(), j;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int l = 2; l < m; ++l) {
            for (int i = 0; i < m - l; ++i) {
                j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
};