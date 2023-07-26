class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int t, h, n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            t = h = 0;
            for (int j = i; j < n; ++j) {
                t += books[j][0];
                h = max(h, books[j][1]);
                if (t > shelfWidth) {
                    break;
                }
                dp[i] = min(dp[i], h + dp[j + 1]);
            }
        }
        return dp[0];
    }
};