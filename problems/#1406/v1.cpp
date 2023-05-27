class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suffixSums(n);
        suffixSums[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSums[i] = suffixSums[i + 1] + stoneValue[i];
        }
        vector<int> dp(n, INT_MIN);
        int score;
        for (int i = n - 1; i >= 0; --i) {
            if (i + 3 >= n) {
                dp[i] = suffixSums[i];
            }
            for (int j = i + 1; j < min(n, i + 4); ++j) {
                score = suffixSums[i] - dp[j];
                dp[i] = max(dp[i], score);
            }
        }
        return suffixSums[0] == 2 * dp[0] ? "Tie" : suffixSums[0] > 2 * dp[0] ? "Bob" : "Alice";
    }
};