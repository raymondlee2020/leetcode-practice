class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left, top, leftop;
        vector<int> dp(n, -1000);
        for (int i = 0; i < m; ++i) {
            left = leftop = -1000;
            for (int j = 0; j < n; ++j) {
                top = dp[j];
                dp[j] = nums1[i] * nums2[j];
                dp[j] = max(dp[j], leftop + dp[j]);
                dp[j] = max(dp[j], left);
                dp[j] = max(dp[j], top);
                left = dp[j];
                leftop = top;
            }
        }
        return dp[n - 1];
    }
};