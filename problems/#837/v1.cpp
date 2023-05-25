class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || (k - 1) + maxPts <= n) {
            return 1.0;
        }
        vector<double> dp(n + 1, 0.0);
        double ret = 0.0;
        double windowSum = 1.0;
        dp[0] = 1.0;
        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;
            if (i < k)  {
                windowSum += dp[i];
            } else {
                ret += dp[i];
            }
            if (i >= maxPts) {
                windowSum -= dp[i - maxPts];
            }
        }

        return ret;
    }
};